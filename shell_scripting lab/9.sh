#Program Number:9
#Name:BTV Sumanth
#Register Number: IMT2020072
#Date: 24/01/22
#Description: Script to display particular set of lines in a given file.




#!/bin/bash

echo Enter filename
read filename

echo starting line number
read start

echo ending line number
read end

a=`expr $start + 1` 
echo The lines between line no. $start and line no. $end of filename $filename are:
tail -n +$a $filename | head -n $((end - start -1))