#!/bin/bash

#The rev command copies the specified files, reversing the order of characters in every line. If no files are specified, the standard input (from keyboard) is read.
reversed=$(rev<<<$*)

echo $reversed