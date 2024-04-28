#!/bin/bash

# Check if a filename is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <filename without extension>"
    exit 1
fi

# Construct the filename with .c extension
filename="$1.c"

# Compile the program
make all FILE="$filename"

# If make was successful, run the program
if [ $? -eq 0 ]; then
    echo "Running the program..."
    make execute TARGET=run
else
    echo "Compilation failed."
fi
