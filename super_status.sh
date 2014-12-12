#!/bin/bash

get_status(){
    base_folder=$PWD
    path=$1

    printf "\033[34m================ Status for $path ================\033[0m\n"
    cd "$path"

    git status

    cd $base_folder
}

get_status . 
get_status llvm 
get_status llvm/tools/clang
get_status llvm/tools/clang/tools/extra
get_status llvm/projects/compiler-rt 
