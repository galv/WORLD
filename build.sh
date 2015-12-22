#/bin/sh
# I am NOT proud of this. Only for Mac OS X
# run from WORLD/ directory.

./waf clean
./waf configure --prefix=.
./waf -v

ln -s  $(pwd)/build/src/libworld.0.dylib $(pwd)/lib/libworld.0.dylib

mkdir -p ground_truth
cd ground_truth
../build/example/test ../example/test16k.wav

echo "Finished"
