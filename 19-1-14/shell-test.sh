#!/bin/bash

`touch 1.txt`
if [ $? -eq "0" ];then
    echo "success"
else
    echo "not succ"
fi
