#Program Number:3
#Name:BTV Sumanth
#Register Number: IMT2020072
#Date: 24/01/22
#Description: Script to create files given the filenames as command line arguments

#!/bin/bash

for i in $*; do 
  touch $i
  echo file $i is created!!  
done