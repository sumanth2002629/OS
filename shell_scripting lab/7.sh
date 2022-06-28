#Program Number:7
#Name:BTV Sumanth
#Register Number: IMT2020072
#Date: 24/01/22
#Description: Script to copy/rename/remove files based on user choice.

#!/bin/bash
echo Enter your choice copy/remove/rename:
read choice
case $choice in
     copy) 
        echo Enter the filename which you want to copy
        read filename 
        echo Enter file/directory where you want to paste $filename
        read destination 
        cp $filename $destination
        echo $filename successfully pasted in $destination;;
     remove) 
        echo Enter the filename that you want to remove
        read filename 
        rm $filename;;
     rename) 
        echo Enter the filename that you want to rename
        read filename 
        echo Enter newname 
        read newname
        mv $filename $newname;;
esac     