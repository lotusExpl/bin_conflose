#!/bin/sh
cd ..
mkdir .conflose
cd bin_conflose
gcc binary.c -o binary
./binary $1
mv $1 .conflose
rm binary

