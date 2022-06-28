#Program Number:15
#Name:BTV Sumanth
#Register Number: IMT2020072
#Date: 24/01/22
#Description: Script using sed 



#!/bin/bash

echo enter your choice 1/2/3/4/5/6/7:
read choice

case $choice in 

        1) 
            echo Enter your search pattern 
            read search_pattern
            sed -n '/'"$search_pattern"'/p' employee.txt;;
        2) 
            echo Enter your search string 
            read search_string
            sed '/'"$search_string"'/d' employee.txt;;
        3)
            echo 'sed -n '/^This.*errors.$/p' example';;

        4) echo Enter the start line number
           read number
           tail -n +$number employee.txt;;

        5) echo Enter the text to be replaced 
           read text1
           echo Enter new text 
           read new_text
           sed 's/'"$text1"'/'"$new_text"'/' employee.txt;;

        6) echo enter the string to display at the start of each line
           read string
           sed 's/^/'"$string"'/' employee.txt;;

        7) echo enter the string to display at the end of each line
           read string
           sed 's/$/'"$string"' /' employee.txt;;





esac