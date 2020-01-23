echo "Enter 1 for head and 2 for tail"
read m

echo "Enter number of lines you want to print"
read n
count=0
while read line
do 
	count=`expr $count + 1`
done < text.txt
echo $count
count1=0
if [ $m -eq 1 ]
then
	while read line
	do
		if [ $count1 -eq $n ]
		then
			break
		fi
		echo $line
		count1=`expr $count1 + 1`
	done < text.txt
	if [ $n -gt $count ]
	then
		echo "The file is completed but still lines required left"
	fi
fi

if [ $m -eq 2 ]
then
count2=`expr $count - $n`
if [ $count2 -lt 0 ]
then 
	count2=0
	echo "The number of lines is less than lines required"
fi
count3=-1
	while read line
	do
		count3=`expr $count3 + 1`
		if [ $count3 -ge $count2 ]
		then	
			echo $line
			count2=`expr $count2 + 1`
		fi
	done < text.txt
fi
