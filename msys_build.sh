#!/bin/sh

set -e

if [ "$ARCH" = x86_64 ]; then
  bits=64
else
  bits=32
fi

# Use this mingw instead of the pre-installed mingw on Appveyor
f=mingw-w$bits-bin-$ARCH-20140102.7z
if ! [ -e $f ]; then
    echo "Downloading $f"
    curl -LsSO https://sourceforge.net/projects/mingw-w64-dgn/files/mingw-w64/$f
fi
7z x $f > /dev/null
export PATH=$PWD/mingw$bits/bin:$PATH

# Build WORLD
cd /c/projects/world
./waf configure --check-cxx-compiler=g++
./waf
