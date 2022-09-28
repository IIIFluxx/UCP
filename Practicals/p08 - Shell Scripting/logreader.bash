#!/bin/bash
file=logfile.txt


if [ $# = 0 ]
then
    echo "a - All log entries recorded on 20 August from"
    echo "    10:21:00am to 10:21:59am."
    echo ""
    echo "b - All log entries containing the words"
    echo "    \"warning\", \"error\" or \"fail\"."
    echo ""
    echo "c - All log entries recorded at a time where"
    echo "    minutes is zero."
    echo ""
    echo "d - All log entries containing an IPv4 addres"
    echo "    - 4 integers seperated by periods."
    echo ""
    echo "e - All log entries containing at least two"
    echo "    IPv4 addresses."

elif [ $1 = a ]
then
    # What I had initially
    # grep -E 'Aug 20 10:21:[0-5][0-9]+' logfile.txt
    # we want it starting with the date ^Aug 20.
    # we want the ending to be anything - .*$
    # .* means any sequence of characters
    # $ means at the end of the line. 

grep -E '^Aug 20 10:21:[0-5][0-9].*$' $file

elif [ $1 = b ]
then
    grep -E '(warning|error|fail)' $file
    #Could also include things at beginning and end since it only asks us to include warning, or error , or fail
    # grep -E '^.*(warning|error|fail)^.$' $file
elif [ $1 = c ]
then
    grep -E '^... .. ..:00:.*$' $file
    #Format: Aug 22 03:00:21 || XXX XX  XX:00:XX
elif [ $1 = d ]
then
    grep -E '^.*[0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?.$' $file
            #Start with any ch, 
elif [ $1 = e ]
then
    grep -E '^.*([0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?)+.*([0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?).*$' $file
        #Starts with any ch, contains at least 2 or 3, contains at least 2 or 3 (total 4 rn). + any ch followed by same thing as before + any ch
    #Alternative way of doing:
    # grep -E '[0-9]{1,3}\.[0-9]{1,3}.\[0-9]{1,3}.\[0-9]{1,3}.*[0-9]{1,3}\.[0-9]{1,3}.\[0-9]{1,3}.\[0-9]{1,3}' $file
fi
