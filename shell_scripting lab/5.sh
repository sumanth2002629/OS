#Program Number:5
#Name:BTV Sumanth
#Register Number: IMT2020072
#Date: 24/01/22
#Description: Script to find the path of a given file.

#!/bin/sh
echo "Enter file to be searched "  
read FILE
ans=`find / -name $FILE 2>/dev/null | wc -l`
ans1=`sudo find / -name $FILE`
if [ $ans = 0 ] 
 then
        echo "The file $FILE doesnt exist"
 else 
    echo $ans1      
fi        
