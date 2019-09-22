#!/bin/sh -f
#
# platform/config/bin/vic-powerstatus.sh
#
# Victor power status monitor
#
# This is a script that can be manually run over ssh to report a few power stats every minute or so. Useful
# for testing, e.g. how long the battery can last without using heavy wifi

CPU_FREQ_FILE="/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq"
THERMO_FILE="/sys/devices/virtual/thermal/thermal_zone3/temp"

TIMER=$SECONDS

while true; do
    
    FREQ="`cat ${CPU_FREQ_FILE}`"
    TEMP="`cat ${THERMO_FILE}`"
    DT=$((SECONDS - TIMER))
    ACTIVE="`ps -o comm | grep 'vic-' | xargs`"
    TIMESTAMP="`date +'%H:%M:%S'`"

    echo -e "${TIMESTAMP}\tactive ${DT}s\tCPU ${FREQ}\ttemperature ${TEMP}\tactive: ${ACTIVE}"

    sleep 10
done
