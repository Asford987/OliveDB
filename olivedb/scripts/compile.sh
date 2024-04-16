#!/bin/bash

# Update the cmake file

SCRIPT_PATH=$(dirname $0)
rm -rf $SCRIPT_PATH/../target/build
cmake -S $SCRIPT_PATH/.. -B $SCRIPT_PATH/../target/build

# Compile the project
cd $SCRIPT_PATH/../target
