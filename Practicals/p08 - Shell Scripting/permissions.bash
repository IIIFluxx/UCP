#!/bin/bash

echo "Please enter a filename"
read filename

if [-r filename]; then
    echo "File is readable"
fi

if [-w filename]; then
    echo "File is writable"
fi

if [-x filename]; then
    echo "File is executable"
fi