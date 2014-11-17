#!/bin/bash -x

# TODO: add support to update upstream

update(){
    base_folder=$PWD
    name=$1
    path=$2
    repo=$3

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

update llvm . git@bitbucket.org:dengels/vprotect-llvm.git
update clang llvm/tools git@bitbucket.org:dengels/vprotect-clang.git
update extra llvm/tools/clang/tools git@bitbucket.org:dengels/vprotect-clang-tools-extra.git
update compiler-rt llvm/projects git@bitbucket.org:dengels/vprotect-compiler-rt.git
