#!/bin/bash
#Check if !exist, R, W, E, RW, RE, WR, WE, RWE, none

# Old - for file in $*; do

for file in $(find -type f); do
    if [ ! -e $file ]; then
        echo "$file does not exist"
    elif [-r $file ] && [-w $file ] && [-x $file ]; then
        echo "$file is readable, writable and executable."
    elif [-r $file ] && [-w $file ]; then
        echo "$file is readable and writable."
    elif [-r $file ] && [-x $file ]; then
        echo "$file is readable and executable."
    elif [-w $file ] && [-x $file ]; then
        echo "$file is writable and executable."
    elif [-w $file ]; then
        echo "$file is only writable."
    elif [-r $file ]; then
        echo "$file is only readable."
    elif [-e $file ]; then
        echo "$file is only executable."
    else
        echo "$file has no permissions"
    fi
done