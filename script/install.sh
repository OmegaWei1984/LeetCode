#!/bin/bash

if [ ! -d ./build ]
then
   mkdir build
fi

cd build

git clone https://github.com/google/googletest.git
cd googletest
mkdir build
cd build
cmake ..

make -j8
sudo make install
