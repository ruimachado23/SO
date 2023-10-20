#!/bin/bash
#This script does a very simple test for checking disk space.
space=$(df -h | awk '{print $5}' | grep % | grep -v Use | sort -n \
   | tail -1 | cut -d "%" -f1 -)
echo "largest occupied space = $space%"
case $space in
    {0-69} )  # espaço < 70%
        Message="All OK."
        ;;
    [70-89] )  # 70% <= espaço < 90%
        Message="Cleaning out. One partition is $space % full."
        ;;
    [90-98] )  # 90% <= espaço < 99%
        Message="Better buy a new disk. One partition is $space % full."
        ;;
    [99] )  # espaço = 99%
        Message="I'm drowning here! There's a partition at $space %!"
        ;;
    * )
        Message="I seem to be running with a non-existent disk..."
        ;;
esac
echo $Message