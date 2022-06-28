#Program Number:14
#Name:BTV Sumanth
#Register Number: IMT2020072
#Date: 24/01/22
#Description: Script to print Good Morning/Good Evening/Good Afternoon based on the current time.





#!/bin/bash

ans=`date | awk '{print $4}' | cut -f1 -d:`

if [ $ans -ge 6 -a $ans -lt 12 ]
    then
    echo Good Morning
elif [ $ans -lt 18 -a $ans -ge 12 ]
    then
        echo Good Afternoon
    else
        echo Good Evening
fi