#!/bin/bash

aaa="a.txt"
`touch $aaa`
test -w $aaa
if [ $? -eq "0" ];
    then 
        echo "$aaa success";
    else 
        echo "$aaa err";
fi


#num1=$[2*3]
#num2=$[1+5]
#if test $[num1] -eq $[num2]
#then
#        echo '两个数字相等!'
#    else
#            echo '两个数字不相等!'
#fi
