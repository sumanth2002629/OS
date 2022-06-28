#Program Number:12
#Name:BTV Sumanth
#Register Number: IMT2020072
#Date: 24/01/22
#Description: Script to print NIT if input was IIT and to print IIT if input was NIT.



#!/bin/bash

case $1 in
     IIT) echo NIT ;;
     NIT) echo IIT ;;
     *) echo STDERR
esac 