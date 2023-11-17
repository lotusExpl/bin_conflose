#!/bin/sh
mv binary.c ..
mv binary.sh ..
rm -rf bin_conflose
cd ..
mkdir .conflose
cd bin_conflose
gcc binary.c -o binary
./binary $1
mv $1 .conflose
rm binary
mv binary.c .conflose
mv binary.sh .conflose

