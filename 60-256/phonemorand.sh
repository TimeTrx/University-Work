#!/bin/bash
#Michael Morand
#
#Assignment 2
#echo -e "Hi, please type the word or number or location: \c "
#read word
new=$(echo $1 | tr -d '(-/\.,)') #$1 is used to pass argv[1] in bash, this seperates certain chars
if [[ $new =~ ^-?[0-9]+$ ]];
then
while read line         #reads the line in the file
do   
theline=$(echo $line | tr -d 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz()-.,\/') 
for words in $theline
do
if [ $new = $words ]; then
echo $line # prints if there is a result
fi
   
done          
done < phonedata.txt
else
new=$(echo $new | tr '[A-Z]' '[a-z]') #makes the chars the same lowercase
while read line         
do   
newline=$(echo $line | tr -d '0123456789()-.,\/') 
     	theline=$(echo $newline | tr '[A-Z]' '[a-z]') #makes the chars the same lowercase
for words in $theline
do
if [ $new = $words ]; then
echo $line  # prints if there is a result
fi
   
done          
done < phonedata.txt 
fi
