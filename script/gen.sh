#!/bin/bash

set -e

# get scripts directory
CMAKE_SOURCE_DIR=$(dirname $(readlink -f $0))
# update cmake source path
CMAKE_SOURCE_DIR=$(pwd)
cd ${CMAKE_SOURCE_DIR}

if [ ! -n "$1" ]; then
    echo "Please input No. and solution name"
    exit 1
else
    ID=$1
    SOLUTION=$2
fi

cp -f ${CMAKE_SOURCE_DIR}/src/no0_template.cpp ${CMAKE_SOURCE_DIR}/src/no${ID}_${SOLUTION}.cpp

sed -i "s/isValid/$(expr ${SOLUTION})/g" \
    ${CMAKE_SOURCE_DIR}/src/no${ID}_${SOLUTION}.cpp

echo "no${ID}_${SOLUTION}.cpp"
