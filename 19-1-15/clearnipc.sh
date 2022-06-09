#!/bin/bash

#check parameters
if [ $# != 2 ];then
    echo "use:$0 user shm|sem|smg|all"
    exit 1
elif [ "$2" != "shm" -a $2 != "sem" -a $2 != "msg" -a $2 != "all" ]
then
    echo "use: $0 user shm|sem|smg|all"
    exit 1
fi

#delect the shm
if [ "$2" == "shm" -o "$2" == "all" ];then
    START=`ipcs|sed -n '/Shared/='`
    END=`ipcs|sed -n '/Semaphore/='`
    for i in `ipcs | sed -n ${START},${END}p|grep $1 | awk '{print $2}'`
    do
        ipcrm shm $i
        echo -e $i
    done
fi
