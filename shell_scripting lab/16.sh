#Program Number:16
#Name:BTV Sumanth
#Register Number: IMT2020072
#Date: 24/01/22
#Description: Script using awk 





#!/bin/bash

echo enter your choice 1/2/3/4/5/6/7:
read choice

case $choice in 

        1) cat employee.txt;;

        2) 
            echo Enter your search pattern 
            read search_pattern
            awk '/'"$search_pattern"'/' employee.txt;;
        3)
            echo Enter the field number you want to display 
            read f_num
            awk '{''print'' $'"$f_num"'}' employee.txt;; 

        4) awk 'BEGIN {print "Name\tDesignation\tDepartment\tSalary";}
           {print $2,"\t",$3,"\t",$4,"\t",$NF;} 
           END {print "Report Generated\n--------------";}' employee.txt ;;

        5) awk '$1 >200' employee.txt ;;

        6)awk '$4 ~/Technology/' employee.txt ;;

        7)awk 'BEGIN { count=0;} 
            $4 ~ /Technology/ { count++; } 
            END { print "Number of employees in Technology Dept =",count;}' employee.txt 
esac            