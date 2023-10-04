#!/bin/bash
# This script checks disk space and identifies the partition with the highest usage.

# Get disk usage information and store it in a variable
disk_info=$(df -h)

# Extract the partition with the highest usage percentage
highest_usage_partition=$(echo "$disk_info" | grep -v 'Filesystem' | sort -k5 -n | tail -n 1 | awk '{print $1}')
space=$(echo "$disk_info" | grep "$highest_usage_partition" | awk '{print $5}' | cut -d '%' -f 1)

# Print the partition with the highest usage and its percentage
echo "Partition with the highest usage: $highest_usage_partition"
echo "Space used on $highest_usage_partition: $space%"

# Determine the message based on the usage percentage
case $space in
    [1-69] )  # space < 70%
        Message="All OK."
        ;;
    [70-89] )  # 70% <= space < 90%
        Message="Cleaning out. $highest_usage_partition is $space% full."
        ;;
    [90-98] )  # 90% <= space < 99%
        Message="Better buy a new disk. $highest_usage_partition is $space% full."
        ;;
    99 )  # space = 99%
        Message="I'm drowning here! $highest_usage_partition is $space% full!"
        ;;
    * )
        Message="I seem to be running with a non-existent disk..."
        ;;
esac

# Print the message
echo "$Message"
