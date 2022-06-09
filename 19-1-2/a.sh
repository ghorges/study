#!/bin/bash

#read是读取
read qerr
echo -e "$qerr\n"
#   $a 传递到脚本的参数个数
echo $#
#   第一个参数
echo $1
#   第二个参数
echo $2
#   显示所有的参数
echo $*
#   返回上一层执行的状态
echo $?
