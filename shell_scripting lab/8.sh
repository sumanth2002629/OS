#Program Number:8
#Name:BTV Sumanth
#Register Number: IMT2020072
#Date: 24/01/22
#Description: Script to check whether the user is logged in or not



#!/bin/bash

echo Enter login name:
read name
if [[ $name = $USER ]]
then
    echo You are logged in $USER!!
else
    echo You are not logged in $name!!
fi    