#!/bin/bash

make -j16
for i in $(echo *.cpp | tr ' ' '\n' | cut -d'.' -f1); do
    echo -n "---- $i ----";

    out1=$(./build/$i.bin 2>&1);
    ret1=$?

    out2=$(./build/$i.mod.bin 2>&1);
    ret2=$?

    if [ "$out1" = "$out2" -a $ret1 -eq $ret2 ]; then
        echo " => Results are equal "
    else
        echo ""
        echo "$out1"
        echo "==> returned : $ret1";
        echo "------------";
        echo "$out2"
        echo "==> returned : $ret2";
        echo "";
    fi
done

