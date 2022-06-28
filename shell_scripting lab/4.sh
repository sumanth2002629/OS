#Program Number:4
#Name:BTV Sumanth
#Register Number: IMT2020072
#Date: 24/01/22
#Description: Script to move files to recycle bin. Filenames are given as command line argumants

#!/bin/bash

for i in $*; do
    mv $i /home/sumanth/.recyclebin
    echo Moved $i to Recycle bin.
done    
