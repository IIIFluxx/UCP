#!/bin/bash

for file in $(find -type f); do
    for file2 in $(find -type f); do
        if [! $file1 = $file2]; then
            if diff $file1 $file2 & >/dev/null; then
                echo "$file1 and $file2"
            fi
        fi
    done
done

# report any pairs in the list that have identical contents (i.e. they contain exactly the same bytes).\
