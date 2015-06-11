#!/bin/bash -x

# Create build directory if it doesn't exist
mkdir -p Debug; 
mkdir -p Release;

cd Debug;

# Configure
cmake -GNinja \
        -DCMAKE_BUILD_TYPE=Debug \
        -DLLVM_ENABLE_ASSERTIONS=ON \
        -DLLVM_BUILD_TESTS=ON \
        -enable-doxygen ../llvm

# Build
ninja


cd ../Release;

# Configure
cmake -GNinja \
        -DCMAKE_BUILD_TYPE=Release \
        -DLLVM_ENABLE_ASSERTIONS=OFF \
        -DLLVM_BUILD_TESTS=OFF \
        ../llvm

# Build
ninja

