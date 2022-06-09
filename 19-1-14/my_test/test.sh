#!/bin/bash

#1.列出上海大盘2014-05-29日的数据
txt=gpdata.txt
time1=2014-05-29
`cat ${txt} | grep /2014-05-29/ `
