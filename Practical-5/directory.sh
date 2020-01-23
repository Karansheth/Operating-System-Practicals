echo "Enter as per your requirement"
echo "1) Enter 1 to create new directory"
echo "2) Enter 2 to modify directory"
echo "3) Enter 3 to navigate to new directory or to any specific path"
echo "4) Enter 4 for listings"
n=1

while [ $n -ne 5 ]
do
read n

case $n in
	1) echo "Enter new Directory name"
	  	 read x
	   	mkdir $x
	;;
	
	2) echo "Choose from: "
	   	echo "1) rename"
		echo "2) copy"
		echo "3) move"
		echo "4) delete"
		read m

		case $m in
			1)echo "Enter name from which you want to move"
			   read y
			   echo "Enter name in which you want to move"
			   read z
			   mv $y $z;;

			2) echo "Enter name from which you want copy"
			   read y
			   echo "Enter name in which you want to copy"
			   read z
			   cp $y $z;;

			3) echo "Enter name from which you want to move"
			   read y
			   echo "Enter name in which you want to move"
			   read z
			   mv $y $z;;

			4)echo "Enter directory you want to delete"
			  read y
			  rmdir $y;;
		esac
	;;
	3) echo "Enter to navigate"
		echo "1) To parent directory"
		echo "2) To specific path"
		read m

		case $m in
			1) cd ..
			   pwd
			;;
			2) echo "Enter the specific path"
			   read y
			   cd $path	
			;;
		esac
	;;
	4) echo "choose from listed below"
		echo "1) list all"
		echo "2) list in reverse order"
		read m
		case $m in
			1) ls -a
			;;
			2) ls -r
			;;
		esac
	;;
	5) break
	;;				
	
esac
done


