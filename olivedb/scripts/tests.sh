#!/bin/bash

# Update the cmake file

SCRIPT_PATH=$(dirname $0)
cmake -S $SCRIPT_PATH/../CMake -B $SCRIPT_PATH/../target

# Compile the project


# Run the tests
