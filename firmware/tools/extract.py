"""
Library and executable to handle OTA firmware image decryption and extraction.
"""

import argparse
import contextlib
import gzip
import logging
import os
import shutil
import subprocess
import tarfile
import tempfile

BOOT_IMG = 'apq8009-robot-boot.img.gz'
SYSFS_IMG = 'apq8009-robot-sysfs.img.gz'

logging.basicConfig(level="INFO", format='%(message)s')


@contextlib.contextmanager
def make_temp_directory():
    temp_dir = tempfile.mkdtemp()
    try:
        yield temp_dir
    finally:
        shutil.rmtree(temp_dir)


def decrypt(encrypted_file, password_file, output_directory):
    output_path = os.path.join(output_directory, encrypted_file + '.dec')

    p = subprocess.Popen(
        ["openssl",
         "enc",
         "-d",
         "-aes-256-ctr",
         "-pass",
         'file:' + password_file,
         "-md",
         "md5",
         "-in",
         encrypted_file,
         '-out',
         output_path],
        shell=False,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )

    return_code = p.wait()
    openssl_out, openssl_err = p.communicate()

    if return_code != 0:
        raise RuntimeError("openssl decryption failed with: {}".format(openssl_err))

    return output_path


def extract_tar(input_file, output_dir):
    logging.info("Extracting {}...".format(os.path.basename(input_file)))
    with tarfile.open(input_file) as tf:
        def is_within_directory(directory, target):
            
            abs_directory = os.path.abspath(directory)
            abs_target = os.path.abspath(target)
        
            prefix = os.path.commonprefix([abs_directory, abs_target])
            
            return prefix == abs_directory
        
        def safe_extract(tar, path=".", members=None, *, numeric_owner=False):
        
            for member in tar.getmembers():
                member_path = os.path.join(path, member.name)
                if not is_within_directory(path, member_path):
                    raise Exception("Attempted Path Traversal in Tar File")
        
            tar.extractall(path, members, numeric_owner=numeric_owner) 
            
        
        safe_extract(tf, path=output_dir)


def extract_gzip(input_file, output_path):
    logging.info("Extracting {}...".format(os.path.basename(input_file)))
    with gzip.open(input_file, 'rb') as compressed:
        with open(output_path, 'wb') as decompressed:
            decompressed.write(compressed.read())


def valid_output_dir(path):
    if os.path.isdir(path) and os.listdir(path):
        raise argparse.ArgumentTypeError("Output directory must be empty: {}".format(path))

    return path


def valid_file(path):
    if not os.path.exists(path):
        raise argparse.ArgumentTypeError("Nothing exists at path: {}".format(path))

    if os.path.isdir(path):
        raise argparse.ArgumentTypeError("Path cannot be a directory: {}".format(path))

    return path


def extract_encrypted_img(filename, output_directory):
    logging.info("Decrypting {}...".format(os.path.basename(filename)))

    with make_temp_directory() as working_dir:
        # Decrypt img gz file
        decrypted_file = decrypt(
            os.path.join(
                output_directory,
                filename),
            arguments.password_file,
            working_dir
        )

        # Extract the img gz file and remove .gz extension
        extracted_file = os.path.join(
            output_directory,
            os.path.splitext(filename)[0]
        )
        extract_gzip(decrypted_file, extracted_file)


def get_args():
    parser = argparse.ArgumentParser(description="Extract an OTA firmware image.")

    parser.add_argument('ota_image', help='firmware image path', type=valid_file)
    parser.add_argument('output_directory', help='output directory to place extracted files', type=valid_output_dir)
    parser.add_argument('password_file', help='ota.pas path', type=valid_file)
    parser.add_argument(
        '--skip-decryption',
        help='skip decryption and extraction of the boot and sysfs images',
        action='store_true',
        default=False)

    return parser.parse_args()


if __name__ == "__main__":
    arguments = get_args()

    # Extract OTA file (tar) into output directory
    extract_tar(arguments.ota_image, arguments.output_directory)

    # Decrypt and extraft the img files
    if not arguments.skip_decryption:
        extract_encrypted_img(BOOT_IMG, arguments.output_directory)
        extract_encrypted_img(SYSFS_IMG, arguments.output_directory)
