#!/bin/bash

if [ $# -ne 4 ]; then
    echo "Usage: run.sh <img_in_0> <img_in_1> <img_out_u> <img_out_v>"
    exit 1
fi

./build/optical_flow "$1" "$2" "$3" "$4"
