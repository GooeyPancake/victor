#!/usr/bin/env python
from __future__ import print_function
"""
Example implementation of Anki Victor Update engine.
"""
__author__ = "Daniel Casner <daniel@anki.com>"

#
# DAS EVENTS Documentation Notice!!!!!
# If you add / modify / remove DAS events from this file, you MUST
# update the DAS macros in update-engine-das-event-documentation.cpp
#

import sys
import os
import urllib2
import subprocess
import tarfile
import zlib
import shutil
import ConfigParser
import socket
import re
from select import select
from hashlib import sha256
from collections import OrderedDict
from fcntl import fcntl, F_GETFL, F_SETFL
from distutils.version import LooseVersion

sys.path.append("/usr/bin")
import update_payload

BOOT_DEVICE = "/dev/block/bootdevice/by-name"
STATUS_DIR = "/run/update-engine"
EXPECTED_DOWNLOAD_SIZE_FILE = os.path.join(STATUS_DIR, "expected-download-size")
EXPECTED_WRITE_SIZE_FILE = os.path.join(STATUS_DIR, "expected-size")
PROGRESS_FILE = os.path.join(STATUS_DIR, "progress")
ERROR_FILE = os.path.join(STATUS_DIR, "error")
DONE_FILE = os.path.join(STATUS_DIR, "done")
MANIFEST_FILE = os.path.join(STATUS_DIR, "manifest.ini")
MANIFEST_SIG = os.path.join(STATUS_DIR, "manifest.sha256")
BOOT_STAGING = os.path.join(STATUS_DIR, "boot.img")
DELTA_STAGING = os.path.join(STATUS_DIR, "delta.bin")
ABOOT_STAGING = os.path.join(STATUS_DIR, "aboot.img")
OTA_PUB_KEY = "/anki/etc/ota.pub"
OTA_ENC_PASSWORD = "/anki/etc/ota.pas"
HTTP_BLOCK_SIZE = 1024*2  # Tuned to what seems to work best with DD_BLOCK_SIZE
HTTP_TIMEOUT = 90 # Give up after 90 seconds on blocking operations
DD_BLOCK_SIZE = HTTP_BLOCK_SIZE*1024
SUPPORTED_MANIFEST_VERSIONS = ["0.9.2", "0.9.3", "0.9.4", "0.9.5", "1.0.0"]
TRUE_SYNONYMS = ["True", "true", "on", "1"]
WIPE_DATA_COOKIE = "/run/wipe-data"
DEBUG = False

def make_blocking(pipe, blocking):
    "Set a filehandle to blocking or not"
    fd = pipe.fileno()
    if not blocking:
        fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | os.O_NONBLOCK)  # set O_NONBLOCK
    else:
        fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) & ~os.O_NONBLOCK)  # clear it

def das_event(name, parameters = []):
    args = ["/anki/bin/vic-log-event", "update-engine", name]
    for p in parameters:
        args.append(p.rstrip().replace('\r', '\\r').replace('\n', '\\n'))
    subprocess.call(args)

def safe_delete(name):
    "Delete a filesystem path name without error"
    if os.path.isfile(name):
        os.remove(name)
    elif os.path.isdir(name):
        shutil.rmtree(name)


def safe_delete_staging_files():
    "Delete staging files"
    safe_delete(BOOT_STAGING)
    safe_delete(DELTA_STAGING)
    safe_delete(ABOOT_STAGING)

def clear_status():
    "Clear everything out of the status directory"
    if os.path.isdir(STATUS_DIR):
        for filename in os.listdir(STATUS_DIR):
            os.remove(os.path.join(STATUS_DIR, filename))


def write_status(file_name, status):
    "Simple function to (over)write a file with a status"
    with open(file_name, "w") as output:
        output.write(str(status))
        output.truncate()


def die(code, text):
    "Write out an error string and exit with given status code"
    write_status(ERROR_FILE, text)
    das_event("robot.ota_download_end", ["fail", get_prop("ro.anki.version"), str(text), "", str(code)])
    if DEBUG:
        sys.stderr.write(str(text))
        sys.stderr.write(os.linesep)
    safe_delete_staging_files()
    exit(code)


def get_slot_name(partition, slot):
    "Get slot dev path name"
    if slot == "f":
        if partition == "system":
            label = "recoveryfs"
        elif partition == "boot":
            label = "recovery"
        else:
            raise ValueError("Unknown partition")
    else:
        label = partition + "_" + slot
    return os.path.join(BOOT_DEVICE, label)


def open_slot(partition, slot, mode):
    "Opens a partition slot"
    return open(os.path.join(BOOT_DEVICE, get_slot_name(partition, slot)), mode + "b")


def zero_slot(target_slot):
    "Writes zeros to the first block of the destination slot boot and system to ensure they aren't booted"
    assert target_slot == 'a' or target_slot == 'b'  # Make sure we don't zero f
    zeroblock = b"\x00"*DD_BLOCK_SIZE
    open_slot("boot", target_slot, "w").write(zeroblock)
    open_slot("system", target_slot, "w").write(zeroblock)


def call(*args):
    "Simple wrapper around subprocess.call to make ret=0 -> True"
    return subprocess.call(*args) == 0


def verify_signature(file_path_name, sig_path_name, public_key):
    "Verify the signature of a file based on a signature file and a public key with openssl"
    openssl = subprocess.Popen(["/usr/bin/openssl",
                                "dgst",
                                "-sha256",
                                "-verify",
                                public_key,
                                "-signature",
                                sig_path_name,
                                file_path_name],
                               shell=False,
                               stdout=subprocess.PIPE,
                               stderr=subprocess.PIPE)
    ret_code = openssl.wait()
    openssl_out, openssl_err = openssl.communicate()
    return ret_code == 0, ret_code, openssl_out, openssl_err


def get_prop(property_name):
    "Gets a value from the property server via subprocess"
    getprop = subprocess.Popen(["/usr/bin/getprop", property_name], shell=False, stdout=subprocess.PIPE)
    if getprop.wait() == 0:
        return getprop.communicate()[0].strip()
    return None


def is_dev_robot(cmdline):
    "Returns true if this robot is a dev robot"
    if "anki.dev" in cmdline:
        return True
    return False


def get_cmdline():
    "Returns /proc/cmdline arguments as a dict"
    cmdline = open("/proc/cmdline", "r").read()
    ret = {}
    for arg in cmdline.split(' '):
        try:
            key, val = arg.split('=')
        except ValueError:
            ret[arg] = None
        else:
            if val.isdigit():
                val = int(val)
            ret[key] = val
    return ret


def get_slot(kernel_command_line):
    "Get the current and target slots from the kernel commanlines"
    suffix = kernel_command_line.get("androidboot.slot_suffix", '_f')
    if suffix == '_a':
        return 'a', 'b'
    elif suffix == '_b':
        return 'b', 'a'
    else:
        return 'f', 'a'


def get_qsn():
    "Retrieve the QSN of the robot"
    return open("/sys/devices/soc0/serial_number", "r").read().strip()


def get_manifest(fileobj):
    "Returns config parsed from INI file in filelike object"
    config = ConfigParser.ConfigParser({'encryption': '0',
                                        'qsn': None,
                                        'ankidev': '0',
                                        'reboot_after_install': '0'})
    config.readfp(fileobj)
    return config


class StreamDecompressor(object):
    "An object wrapper for handling possibly encrypted, compressed files"

    def __init__(self, src_file, encryption, compression, expected_size, do_sha=False):
        "Sets up the decompressor with it's subprocess, pipes etc."
        self.fileobj = src_file
        self.len = expected_size
        self.pos = 0
        self.sum = sha256() if do_sha else None
        cmds = []
        if encryption == 1:
            cmds.append("openssl enc -d -aes-256-ctr -pass file:{0}".format(OTA_ENC_PASSWORD))
        elif encryption != 0:
            die(210, "Unsupported encryption scheme {}".format(encryption))
        if compression == 'gz':
            cmds.append("gunzip")
        elif compression:
            die(205, "Unsupported compression scheme {}".format(compression))
        if cmds:
            self.proc = subprocess.Popen(" | ".join(cmds), shell=True,
                                         stdin=subprocess.PIPE,
                                         stdout=subprocess.PIPE,
                                         stderr=sys.stderr)
            make_blocking(self.proc.stdout, False)
        else:
            die(201, "Unhandled section format for expansion")

    def __del__(self):
        "Ensure all subprocesses are closed when class goes away"
        if self.proc.poll() is None:
            self.proc.kill()

    def read(self, length=-1):
        """Pumps the input and reads output"""
        block = b""
        while (length < 0 or len(block) < length) and (self.pos + len(block)) < self.len:
            rlist, wlist, xlist = select((self.proc.stdout,),
                                         (self.proc.stdin,),
                                         (self.proc.stdout, self.proc.stdin))
            if xlist:
                die(212, "Decompressor subprocess exceptional status")
            if self.proc.stdin in wlist:
                curl = self.fileobj.read(HTTP_BLOCK_SIZE)
                if len(curl) == HTTP_BLOCK_SIZE:
                    self.proc.stdin.write(curl)
                else:  # End the communication
                    block += self.proc.communicate(curl)[0]
                    break
            if self.proc.stdout in rlist:
                read_len = length - len(block) if length >= 0 else length
                block += self.proc.stdout.read(read_len)
        if self.sum:
            self.sum.update(block)
        self.pos += len(block)
        return block

    def digest(self):
        "Calculate the hexdigest if shasum has been being calculated"
        return self.sum.hexdigest() if self.sum else None

    def tell(self):
        "Return the number of bytes output so far"
        return self.pos

    def read_to_file(self, out_fh, block_size=DD_BLOCK_SIZE, progress_callback=None):
        "Read the entire contents to a given file"
        while self.pos < self.len:
            out_fh.write(self.read(block_size))
            if callable(progress_callback):
                progress_callback(self.pos)


def open_url_stream(url):
    "Open a URL as a filelike stream"
    try:
        assert url.startswith("http")  # Accepts http and https but not ftp or file
        os_version = get_prop("ro.anki.version")
        victor_version = get_prop("ro.anki.victor.version")
        if '?' in url:  # Already has a query string
            if not url.endswith('?'):
                url += '&'
        else:
            url += '?'
        url += "emresn={0:s}&ankiversion={1:s}&victorversion={2:s}".format(
                get_prop("ro.serialno"),
                os_version,
                victor_version)
        request = urllib2.Request(url)
        opener = urllib2.build_opener()
        opener.addheaders = [('User-Agent', 'Victor-OTA/{0:s}'.format(os_version))]
        return opener.open(request, timeout=HTTP_TIMEOUT)
    except Exception as e:
        die(203, "Failed to open URL: " + str(e))


def make_tar_stream(fileobj, open_mode="r|"):
    "Converts a file like object into a streaming tar object"
    try:
        return tarfile.open(mode=open_mode, fileobj=fileobj)
    except Exception as e:
        die(204, "Couldn't open contents as tar file " + str(e))


class ShaFile(object):
    "A fileobject wrapper that calculates a sha256 digest as it's processed"

    def __init__(self, fileobj):
        "Setup the wrapper"
        self.fileobj = fileobj
        self.sum = sha256()
        self.len = 0

    def read(self, *args):
        "Read function wrapper which adds calculates the shasum as it goes"
        block = self.fileobj.read(*args)
        self.sum.update(block)
        self.len += len(block)
        return block

    def digest(self):
        "Calculate the hexdigest"
        return self.sum.hexdigest()

    def bytes(self):
        "Return the total bytes read from the file"
        return self.len


def extract_ti(manifest, tar_stream, expected_name, section, dest_fh, progress_callback):
    "Extract an image from a tar_info object"
    tar_info = tar_stream.next()
    if not tar_info.name.endswith(expected_name):
        die(200, "Expected \"{0}\" to be next in tar but found \"{1}\"".format(expected_name, tar_info.name))
    decompressor = StreamDecompressor(tar_stream.extractfile(tar_info),
                                      manifest.getint(section, "encryption"),
                                      manifest.get(section, "compression"),
                                      manifest.getint(section, "bytes"),
                                      True)
    decompressor.read_to_file(dest_fh, DD_BLOCK_SIZE, progress_callback)
    if decompressor.digest() != manifest.get(section, "sha256"):
        return False
    else:
        return decompressor.tell()


def handle_boot_system(target_slot, manifest, tar_stream):
    "Process 0.9.2 format manifest files"
    total_size = manifest.getint("BOOT", "bytes") + manifest.getint("SYSTEM", "bytes")
    write_status(EXPECTED_WRITE_SIZE_FILE, total_size)
    written_size = 0
    write_status(PROGRESS_FILE, written_size)

    def progress_update(progress):
        "Update progress while writing to slots"
        write_status(PROGRESS_FILE, written_size + progress)
        if DEBUG:
            sys.stdout.write("{0:0.3f}\r".format(float(written_size+progress)/float(total_size)))
            sys.stdout.flush()

    # Extract boot image
    if DEBUG:
        print("Boot")
    extract_result = extract_ti(manifest, tar_stream, "boot.img.gz", "BOOT", open(BOOT_STAGING, "wb"), progress_update)
    if extract_result is False:
        zero_slot(target_slot)
        die(209, "Boot image hash doesn't match signed manifest")
    written_size += extract_result

    # Extract system images
    if DEBUG:
        print("System")
    extract_result = extract_ti(manifest, tar_stream, "sysfs.img.gz", "SYSTEM",
                                open_slot("system", target_slot, "w"),
                                progress_update)
    if extract_result is False:
        zero_slot(target_slot)
        die(209, "System image hash doesn't match signed manifest")
    written_size += extract_result

    # Actually write the boot image now
    with open(BOOT_STAGING, "rb") as src:
        with open_slot("boot", target_slot, "w") as dst:
            dst.write(src.read())

    # Delete the staged boot.img file
    safe_delete(BOOT_STAGING)


def copy_slot(partition, src_slot, dst_slot):
    "Copy the contents of a partition slot from one to the other"
    with open_slot(partition, src_slot, "r") as src:
        with open_slot(partition, dst_slot, "w") as dst:
            buffer = src.read(DD_BLOCK_SIZE)
            while len(buffer) == DD_BLOCK_SIZE:
                dst.write(buffer)
                buffer = src.read(DD_BLOCK_SIZE)
            dst.write(buffer)


def handle_delta(current_slot, target_slot, manifest, tar_stream):
    "Apply a delta update to the boot and system partitions"
    current_version = get_prop("ro.anki.version")
    delta_base_version = manifest.get("DELTA", "base_version")
    if current_version != delta_base_version:
        die(211, "My version is {} not {}".format(current_version, delta_base_version))
    delta_bytes = manifest.getint("DELTA", "bytes")
    download_progress_denominator = 4  # Download expected not to take more than 25% of the time
    write_status(EXPECTED_WRITE_SIZE_FILE, delta_bytes*download_progress_denominator)
    write_status(PROGRESS_FILE, 0)

    def progress_update(progress):
        "Update delta download progress"
        write_status(PROGRESS_FILE, progress)
        if DEBUG:
            sys.stdout.write("{0:0.3f}\r".format(float(progress)/float(delta_bytes*download_progress_denominator)))
            sys.stdout.flush()

    # Extract delta file
    if DEBUG:
        print("Delta")
    extract_result = extract_ti(manifest, tar_stream, "delta.bin.gz", "DELTA",
                                open(DELTA_STAGING, "wb"),
                                progress_update)
    if extract_result is False:
        die(209, "delta.bin hash doesn't match manifest value")
    try:
        payload = update_payload.Payload(open(DELTA_STAGING, "rb"))
        payload.Init()

        # Update progress estimate
        num_operations = len(payload.manifest.install_operations) + len(payload.manifest.kernel_install_operations)
        progress = (num_operations + 1) / (download_progress_denominator - 1)
        num_operations += progress
        write_status(PROGRESS_FILE, progress)
        write_status(EXPECTED_WRITE_SIZE_FILE, num_operations)

        def progress_ticker(start, total):
            "Delta application callback"
            progress = start
            while True:
                progress += 1
                write_status(PROGRESS_FILE, progress)
                if DEBUG:
                    sys.stdout.write("{0:0.3f}\r".format(float(progress)/float(total)))
                    sys.stdout.flush()
                yield

        payload.progress_tick_callback = progress_ticker(progress, num_operations)
        payload.Apply(get_slot_name("boot", target_slot),
                      get_slot_name("system", target_slot),
                      get_slot_name("boot", current_slot),
                      get_slot_name("system", current_slot),
                      truncate_to_expected_size=False)

        safe_delete(DELTA_STAGING)

    except update_payload.PayloadError as pay_err:
        zero_slot(target_slot)
        die(207, "Delta payload error: {!s}".format(pay_err))

def handle_factory(manifest, tar_stream):
    "Update factory partitions"
    total_size = manifest.getint("ABOOT", "bytes") + \
                 manifest.getint("RECOVERY", "bytes") + \
                 manifest.getint("RECOVERYFS", "bytes")
    write_status(EXPECTED_WRITE_SIZE_FILE, total_size)
    written_size = 0
    write_status(PROGRESS_FILE, written_size)
    target_slot = 'f'

    def progress_update(progress):
        "Update progress while writing to slots"
        write_status(PROGRESS_FILE, written_size + progress)
        if DEBUG:
            sys.stdout.write("{0:0.3f}\r".format(float(written_size+progress)/float(total_size)))
            sys.stdout.flush()

    # Install new aboot, recovery, recoverfs
    if DEBUG:
        print("ABoot")
    extract_result = extract_ti(manifest, tar_stream, "emmc_appsboot.img.gz", "ABOOT",
                                open(ABOOT_STAGING, "wb"),
                                progress_update)
    if extract_result is False:
        die(209, "aboot hash doesn't match signed manifest")
    else:
        written_size += extract_result
    if DEBUG:
        print("recovery")
    extract_result = extract_ti(manifest, tar_stream, "boot.img.gz", "RECOVERY",
                                open(BOOT_STAGING, "wb"),
                                progress_update)
    if extract_result is False:
        die(209, "Boot image hash doesn't match signed manifest")
    written_size += extract_result
    # Extract system images
    if DEBUG:
        print("recoveryfs")
    extract_result = extract_ti(manifest, tar_stream, "sysfs.img.gz", "RECOVERYFS",
                                open_slot("system", target_slot, "w"),
                                progress_update)
    if extract_result is False:
        zero_slot(target_slot)
        die(209, "System image hash doesn't match signed manifest")
    written_size += extract_result
    # Actually write the boot image now
    with open(BOOT_STAGING, "rb") as src:
        with open_slot("boot", target_slot, "w") as dst:
            dst.write(src.read())

    # Delete the staged boot.img file
    safe_delete(BOOT_STAGING)

    # And actually write the aboot image
    with open(ABOOT_STAGING, "rb") as src:
        with open(os.path.join(BOOT_DEVICE, "aboot"), "wb") as dst:
            dst.write(src.read())

    # Delete the staged aboot.img file
    safe_delete(ABOOT_STAGING)

def validate_new_os_version(current_os_version, new_os_version, cmdline):
    allow_downgrade = os.getenv("UPDATE_ENGINE_ALLOW_DOWNGRADE", "False") in TRUE_SYNONYMS
    if allow_downgrade and is_dev_robot(cmdline):
        return
    os_version_regex = re.compile('^(?:\d+\.){2,3}\d+(d|ud)?$')
    m = os_version_regex.match(new_os_version)
    if not m:
        die(216, "OS version " + new_os_version + " does not match regular expression")
    new_os_version_suffix = m.groups()[0]
    m = os_version_regex.match(current_os_version)
    current_os_version_suffix = m.groups()[0]
    if new_os_version_suffix != current_os_version_suffix:
        die(216, "Update from " + current_os_version + " to " + new_os_version + " not allowed")
    if LooseVersion(new_os_version) < LooseVersion(current_os_version):
        die(216, "Downgrade from " + current_os_version + " to " + new_os_version + " not allowed")
    return

def update_from_url(url):
    "Updates the inactive slot from the given URL"
    # Figure out slots
    cmdline = get_cmdline()
    current_slot, target_slot = get_slot(cmdline)
    if DEBUG:
        print("Target slot is", target_slot)
    # Make status directory
    if not os.path.isdir(STATUS_DIR):
        os.mkdir(STATUS_DIR)
    # Open URL as a tar stream
    stream = open_url_stream(url)
    content_length = stream.info().getheaders("Content-Length")[0]
    write_status(EXPECTED_DOWNLOAD_SIZE_FILE, content_length)
    current_os_version = get_prop("ro.anki.version")
    next_boot_os_version = current_os_version
    is_factory_update = False
    reboot_after_install = 0
    with make_tar_stream(stream) as tar_stream:
        # Get the manifest
        if DEBUG:
            print("Manifest")
        manifest_ti = tar_stream.next()
        if not manifest_ti.name.endswith('manifest.ini'):
            die(200, "Expected manifest.ini at beginning of download, found \"{0.name}\"".format(manifest_ti))
        with open(MANIFEST_FILE, "wb") as manifest:
            manifest.write(tar_stream.extractfile(manifest_ti).read())
        manifest_sig_ti = tar_stream.next()
        if not manifest_sig_ti.name.endswith('manifest.sha256'):
            die(200, "Expected manifest signature after manifest.ini. Found \"{0.name}\"".format(manifest_sig_ti))
        with open(MANIFEST_SIG, "wb") as signature:
            signature.write(tar_stream.extractfile(manifest_sig_ti).read())
        verification_status = verify_signature(MANIFEST_FILE, MANIFEST_SIG, OTA_PUB_KEY)
        if not verification_status[0]:
            die(209,
                "Manifest failed signature validation, openssl returned {1:d} {2:s} {3:s}".format(*verification_status))
        # Manifest was signed correctly
        manifest = get_manifest(open(MANIFEST_FILE, "r"))
        # Inspect the manifest
        if manifest.get("META", "manifest_version") not in SUPPORTED_MANIFEST_VERSIONS:
            die(201, "Unexpected manifest version")
        reboot_after_install = manifest.getint("META", "reboot_after_install")
        next_boot_os_version = manifest.get("META", "update_version")
        validate_new_os_version(current_os_version, next_boot_os_version, cmdline)
        if DEBUG:
            print("Updating to version {}".format(next_boot_os_version))
        if is_dev_robot(cmdline):
            if not manifest.getint("META", "ankidev"):
                die(214, "Ankidev OS can't install non-ankidev OTA file")
        elif manifest.getint("META", "ankidev"):
            die(214, "Non-ankidev OS can't install ankidev OTA file")
        # Mark target unbootable
        if not call(['/bin/bootctl', current_slot, 'set_unbootable', target_slot]):
            die(202, "Could not mark target slot unbootable")
        zero_slot(target_slot)  # Make it doubly unbootable just in case
        num_images = manifest.getint("META", "num_images")
        if num_images == 2:
            if manifest.has_section("BOOT") and manifest.has_section("SYSTEM"):
                handle_boot_system(target_slot, manifest, tar_stream)
            else:
                die(201, "Two images specified but couldn't find boot or system")
        elif num_images == 1:
            if manifest.has_section("DELTA"):
                handle_delta(current_slot, target_slot, manifest, tar_stream)
            else:
                die(201, "One image specified but not DELTA")
        elif num_images == 3:
            if manifest.has_section("ABOOT") and manifest.has_section("RECOVERY") and manifest.has_section("RECOVERYFS"):
                if manifest.get("META", "qsn") == get_qsn():
                    handle_factory(manifest, tar_stream)
                    is_factory_update = True
                else:
                    die(213, "QSN doesn't match manifest")
            else:
                die(201, "3 images specified but not factory update")
        else:
            die(201, "Unexpected manifest configuration")
    stream.close()
    # Ensure new images are synced to disk
    if not call(["/bin/sync"]):
        die(208, "Couldn't sync OS images to disk")
    # Mark the slot bootable now
    if not is_factory_update:
        if not call(["/bin/bootctl", current_slot, "set_active", target_slot]):
            die(202, "Could not set target slot as active")
    else: # Is a factory update, mark both update slots unbootable and erase user data
        write_status(WIPE_DATA_COOKIE, 1)
        if not call(["/bin/bootctl", current_slot, "set_unbootable", 'a']):
            die(202, "Could not set a slot as unbootable")
        if not call(["/bin/bootctl", current_slot, "set_unbootable", 'b']):
            die(202, "Could not set b slot as unbootable")
    safe_delete(ERROR_FILE)
    write_status(DONE_FILE, 1)
    das_event("robot.ota_download_end", ["success", next_boot_os_version])
    if reboot_after_install:
        os.system("/sbin/reboot")

def logv(msg):
    if DEBUG:
        print(msg)
        sys.stdout.flush()

def loge(msg):
    print(msg, file=sys.stderr)
    sys.stderr.flush()

def generate_shard_id():
    override_shard = os.getenv("UPDATE_ENGINE_SHARD", None)
    if override_shard:
        return override_shard
    esn = get_prop("ro.serialno")
    b = int(sha256(esn).hexdigest(), 16) % 100
    return "{:02d}".format(b)

def construct_update_url(os_version, cmdline):
    base_url = os.getenv("UPDATE_ENGINE_BASE_URL", None)
    if is_dev_robot(cmdline):
        base_url = os.getenv("UPDATE_ENGINE_ANKIDEV_BASE_URL", base_url)
    if not base_url:
        return None
    ota_type = os.getenv("UPDATE_ENGINE_OTA_TYPE", "diff")
    shard_part = ""
    use_sharding = os.getenv("UPDATE_ENGINE_USE_SHARDING", "False") in TRUE_SYNONYMS
    if use_sharding:
        shard_part = generate_shard_id() + "/"
    url = "{0}{1}{2}/{3}.ota".format(base_url, shard_part, ota_type, os_version.rstrip("ud"))
    return url

if __name__ == '__main__':
    das_event("robot.ota_download_start")
    clear_status()
    DEBUG = os.getenv("UPDATE_ENGINE_DEBUG", "False") in TRUE_SYNONYMS
    url = os.getenv("UPDATE_ENGINE_URL", "auto")
    if len(sys.argv) > 1:
        url = sys.argv[1]
    if len(sys.argv) > 2 and sys.argv[2] == '-v':
        DEBUG = True
    if url == "auto":
        logv("Automatic update running.....")
        url = construct_update_url(get_prop("ro.anki.version"), get_cmdline())
        if not url:
            loge("Unable to construct automatic update url")
            die(203, "Unable to construct automatic update url")
        logv("Automatic URL = {}".format(url))

    if DEBUG:
        update_from_url(url)
    else:
        try:
            update_from_url(url)
        except zlib.error as decompressor_error:
            die(205, "Decompression error: " + str(decompressor_error))
        except socket.timeout as timeout_error:
            das_event("robot.ota_download_stalled")
            die(215, "Socket Timeout: " + str(timeout_error))
        except IOError as io_error:
            die(208, "IO Error: " + str(io_error))
        except Exception as e:
            die(219, e)
    safe_delete_staging_files()
    exit(0)
