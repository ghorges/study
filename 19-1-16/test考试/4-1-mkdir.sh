#!/bin/bash

i=50

while [ $i -ne 0 ]
do
    mkdir "/home/user${i}"
    chmod 751 "/home/user${i}"
    let i--
done
