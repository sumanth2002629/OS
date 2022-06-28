#Program Number:6
#Name:BTV Sumanth
#Register Number: IMT2020072
#Date: 24/01/22
#Description: Script to execute the command based on the user choice

#!/bin/bash

echo Enter your choice 1/2/3/4:
read choice
case $choice in
     1) ls ;;
     2) pwd ;;
     3) who ;;
     4) exit ;;  # exit not working
esac     