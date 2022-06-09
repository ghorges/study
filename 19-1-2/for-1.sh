#!/bin/bash


i=1
# 这个就是遍历参数
for param
do
    echo "param $i is $param"
    # 这要有let
    let i++
done
