#!/bin/bash

day=$(date +"%d") # Command - retrieves the current day of the month. 

# Remember. date <--- on its own = Mon Jun  8 21:44:23 AWST 2020
# $(date) <---- surrounding by brackets means we substitute it in as a string. 

for filename in $(find -type f); do # For all (normal) files in all subdirectories.

    if [[ "$filename" == *"$day"* ]]; then # If filename == current day

        echo "$filename" 
    fi
done
