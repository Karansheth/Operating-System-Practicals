echo "Enter the number"
read n

i=0

j=1

echo $j
count=1
while [ $count -lt $n ]
do 	
	m=`expr $i + $j`
	i=$j
	j=$m
	count=`expr $count + 1`
	echo $m
done
