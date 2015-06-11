#!/bin/bash -x

# TODO: add support to update upstream

update(){
    base_folder=$PWD
    name=$1
    path=$2
    repo=git@github.com:vprotect-llvm/$3

    cd $path

    # Create the repo if it doesn't exist
    if [ ! -d $name ]; then
        git clone $repo $name
    else
        # Otherwise try to pull and update
        cd $name
       
        git pull
    fi

    cd $base_folder
}

update llvm         .                       llvm.git
update clang        llvm/tools              clang.git
update extra        llvm/tools/clang/tools  clang-tools-extra.git
update compiler-rt  llvm/projects           compiler-rt.git
