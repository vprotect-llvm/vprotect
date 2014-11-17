#!/bin/bash -x

# Create build directory if it doesn't exist
mkdir -p build; 
cd build;

# Configure
if [ -f /usr/bin/clang -a -f /usr/bin/clang++ ]; then
    export CC=/usr/bin/clang
    export CXX=/usr/bin/clang++

    cmake -GNinja \
        -DCMAKE_BUILD_TYPE=Debug \
        -DLLVM_ENABLE_ASSERTIONS=ON \
        -DLLVM_BUILD_TESTS=ON \
        -DLLVM_BINUTILS_INCDIR=/usr/include \
        -DCMAKE_CXX_COMPILER=/usr/bin/clang++ \
        -enable-doxygen ../llvm
else
    
    cmake -GNinja \
        -DCMAKE_BUILD_TYPE=Debug \
        -DLLVM_ENABLE_ASSERTIONS=ON \
        -DLLVM_BUILD_TESTS=ON \
        -DLLVM_BINUTILS_INCDIR=/usr/include \
        -enable-doxygen ../llvm
fi 

# Build
ninja
