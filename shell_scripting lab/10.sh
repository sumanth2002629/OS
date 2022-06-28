#Program Number:10
#Name:BTV Sumanth
#Register Number: IMT2020072
#Date: 27/01/22
#Description: Script to backup the given directory to a given filename

#!/bin/bash
echo give the existing directory path.
read dir_path
echo Enter the backup filename with tar.gz extension
read back_up #enter with tar.gz extension

ans=`tar -zcvf $back_up $dir_path`
echo directory $dir_path successfully backed up $ans