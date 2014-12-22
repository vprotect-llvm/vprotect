#!/bin/bash

make -j16
for i in $(echo *.cpp | tr ' ' '\n' | cut -d'.' -f1); do 
    echo "---- $i ----";
    ./build/$i.bin; 
    echo "==> returned : $?"; 
    echo "------------";
    ./build/$i.mod.bin; 
    echo "==> returned : $?"; 
    echo ""; 
done

