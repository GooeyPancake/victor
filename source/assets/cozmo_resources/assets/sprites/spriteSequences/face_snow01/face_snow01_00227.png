#!/usr/bin/env python
from __future__ import print_function

"""
Reboot the robot, if it is safe to do so, to clear out the cobwebs.
"""
__author__ = "Stuart Eichert <seichert@anki.com>"

import datetime
import os
import random
import subprocess
import sys
import time

INHIBITOR_FILES = ['/data/inhibit_reboot', '/run/inhibit_reboot']
INTERPRETERS = ['python']
LOCALTIME_FILE = "/data/etc/localtime"
DEFAULT_TIMEZONE = "/usr/share/zoneinfo/Universal"

UPDATER_PROCESS = "/anki/bin/update-engine"

earliest = int(os.getenv("REBOOTER_EARLIEST", 1 * 60 * 60))  # 1 AM
latest = int(os.getenv("REBOOTER_LATEST", 5 * 60 * 60))  # 5 AM
minimum_uptime = int(os.getenv("REBOOTER_MINIMUM_UPTIME", 4 * 60 * 60))  # 4 hr
inhibitor_delay = int(os.getenv("REBOOTER_INHIBITOR_DELAY", 17))  # 17 seconds
verbose_logging = os.getenv("REBOOTER_VERBOSE_LOGGING", False)


def das_event(name, parameters = []):
    args = ["/anki/bin/vic-log-event", "rebooter.py", name]
    for p in parameters:
        args.append(p.rstrip().replace('\r', '\\r').replace('\n', '\\n'))
    subprocess.call(args)


def log_das_event_for_failure(reason):
    das_event("robot.maintenance_reboot", ["fail", reason])


def write_status(file_name, status):
    "Simple function to (over)write a file with a status"
    with open(file_name, "w") as output:
        output.write(str(status))
        output.truncate()


def reboot():
    if verbose_logging:
        print("Reboot time has arrived.  See you on the other side....")
        sys.stdout.flush()
    das_event("robot.maintenance_reboot", ["success"])
    write_status("/data/maintenance_reboot", 1)
    os.system("/sbin/reboot")


def uptime():
    up, idle = [float(field) for field in open("/proc/uptime").read().split()]
    return int(up)


def now():
    now_obj = datetime.datetime.now()
    now = (now_obj.hour * 60 * 60) + (now_obj.minute * 60) + now_obj.second
    return now


def exit_if_too_late(reason="late"):
    if now() > latest:
        print("Too late. Exiting.")
        log_das_event_for_failure(reason)
        sys.exit()


def print_and_sleep(msg, delay):
    if verbose_logging:
        print("{0}.  Sleeping for {1} seconds.....".format(msg, delay))
        sys.stdout.flush()
    time.sleep(delay)


def processes():
    processes = []
    # Collect only the pid (process identifier) directories from under /proc
    # We don't want things like /proc/kmsg or /proc/misc
    pids = [pid for pid in os.listdir('/proc') if pid.isdigit()]

    for pid in pids:
        try:
            with open(os.path.join('/proc', pid, 'cmdline'), 'rb') as f:
                cmd = f.read()
                if len(cmd) > 0:
                    args = cmd.split('\0')
                    if args[0] in INTERPRETERS and len(args) > 1:
                        processes.append(args[1])
                    else:
                        processes.append(args[0])
        except IOError:
            continue

    return processes

def is_os_update_pending():
    return os.path.exists("/run/update-engine/done")


def inhibitors():
    inhibitors = [file for file in INHIBITOR_FILES if os.path.exists(file)]
    if is_os_update_pending():
        return inhibitors

    powersave = False
    try:
        governor = '/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor'
        setting = open(governor, 'rb').read()
        powersave = setting.startswith("powersave") or setting.startswith("userspace")
    except IOError:
        pass

    if not powersave:
        inhibitors.append("powersave")

    if UPDATER_PROCESS in processes():
        inhibitors.append(UPDATER_PROCESS)
    return inhibitors

if not is_os_update_pending():
    # Check that we have a local timezone and not just the default
    if not os.path.exists(LOCALTIME_FILE):
        print("{0} does not exist.  Exiting.".format(LOCALTIME_FILE))
        sys.stdout.flush()
        log_das_event_for_failure("no_timezone")
        sys.exit()

    if os.path.realpath(LOCALTIME_FILE) == DEFAULT_TIMEZONE:
        print("Local timezone has not been set.  Exiting.")
        sys.stdout.flush()
        log_das_event_for_failure("default_timezone")
        sys.exit()

    exit_if_too_late()

# systemd should start us at 1AM or a little later, but just in case, sleep
# if we are run too early
if now() < earliest:
    sleep = earliest - now()
    print_and_sleep("Too early", sleep)

if not is_os_update_pending():
    exit_if_too_late()

    # If we have rebooted recently, don't bother doing this periodic reboot
    if uptime() < minimum_uptime:
        sleep_needed = minimum_uptime - uptime()
        max_sleep = latest - now()
        if sleep_needed > max_sleep:
            print("Uptime not met.  Exiting...")
            log_das_event_for_failure("uptime")
            sys.exit()
        print_and_sleep("Uptime not met", sleep_needed)

    exit_if_too_late()

# Random sleep to avoid hitting servers at the same time
max_sleep = max(1, latest - now() - 60)
random_sleep = random.randint(1, max_sleep)
print_and_sleep("Random delay to be nice to servers", random_sleep)

if not is_os_update_pending():
    exit_if_too_late()

# Wait until all the inhibitors are cleared
while len(inhibitors()) > 0:
    exit_if_too_late(reason = str(inhibitors()))
    print_and_sleep("{0} exists".format(inhibitors()), inhibitor_delay)

reboot()
