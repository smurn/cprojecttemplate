#!/usr/bin/env bash
set -o nounset
set -o errexit
rm -rf build
mkdir build
cd build
cmake .. # -DCMAKE_VERBOSE_MAKEFILE=ON ..
make
make test
make doc
