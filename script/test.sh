set -e

# get scripts directory
CMAKE_SOURCE_DIR=$(dirname $(readlink -f $0))
# update cmake source path
CMAKE_SOURCE_DIR=$(pwd)
cd ${CMAKE_SOURCE_DIR}
echo $CMAKE_SOURCE_DIR

if [ ! -d ./build ] 
then
   mkdir build 
fi

cd build && cmake ..  && make $1 -j8 && cd src 

./$1
