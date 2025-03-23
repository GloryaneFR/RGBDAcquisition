#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd "$DIR"

cd ..
REPO="$( pwd )"
cd "$DIR"

echo "JIT Python/C Compilation *made by AmmarTM* handled by : "
BVHTESTER_OBJ_DIR="$REPO/RGBDAcquisition/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/build/src/Applications/BVHTester/BVHTester.dir/Release"
PTHREAD_LIB_DIR="$REPO/pthreads4w/PTHREADS-BUILT/x86_64/Debug/lib"

# Create shared library DLL file
link -DLL -out:libBVHConverter.dll "$BVHTESTER_OBJ_DIR/*.obj" "$PTHREAD_LIB_DIR/pthread.lib" -verbose


if [ $? -ne 0 ]; then
    echo "Error: Unable to compile BVH library, This probably means that you have library dependencies missing ..."
    echo "Try : sudo apt install build-essential libglew-dev freeglut3-dev"
fi



exit 0
