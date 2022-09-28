#!/bin/bash
for file in $*.txt; do
    if [^-e $file ]; then
    make
    ./main *.txt
    elif [-e $file ]; then
    ./main *.txt
done