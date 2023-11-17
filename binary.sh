#!/bin/sh
mv binary.c ..
mv binary.sh ..
cd ..
rm -rf bin_conflose
mkdir .conflose
gcc binary.c -o binary
./binary $1
mv $1 .conflose
rm binary
mv binary.c .conflose
mv binary.sh .conflose

