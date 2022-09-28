#!/bin/bash
echo "Please enter the name of the first file"
read file1

echo "Please enter the name of the second file"
read file2

if [file1 -nt $file2 ]; then
    echo "First file is newer"
else
    echo "Second file is newer"
fi