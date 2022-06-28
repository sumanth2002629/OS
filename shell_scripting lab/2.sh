#Program Number:2
#Name:BTV Sumanth
#Register Number: IMT2020072
#Date: 24/01/22
#Description: Script to check number of command line arguments are equal to 3 or not

#!/bin/bash
VAR=$#
if [[ $VAR -eq 3 ]]
then
  echo $@
else
    echo "Error!"
fi
