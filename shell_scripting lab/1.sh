#Program Number:1
#Name:BTV Sumanth
#Register Number: IMT2020072
#Date: 24/01/22
#Description: Script to count number of block device files in /dev directory


#!/bin/sh

ans=`ls -Rl /dev | grep ^b | wc -l`
echo Number of block device files in /dev directory is $ans

