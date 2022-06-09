#!/bin/bash

read aaa
case $aaa in
1)
    echo "you select 1"
    ;;
2)
    echo "you 2"
    ;;
3)
    echo "you 3"
    ;;
*)
    echo " other"
    exit;
    ;;
    
esac
