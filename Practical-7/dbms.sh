

while [ 1 ]

do

echo " "

echo " "

echo " "

echo " The database management system operations :  "

echo " 1.For inserting data into the file "

echo " 2.View all record of file "

echo " 3.For searching the data from the file "

echo " 4.For modifying the data into the file "

echo " 5.For Delete the record "

echo " 6.For Exit "

echo " Enter your choice : "

read choice

clear

case $choice in

        1)echo " Enter the data you want to enter in the file "

          echo " Enter the roll no "

          read rno

          echo " Enter the name "

          read name

          echo " Enter the branch "

          read branch

          echo " Enter the Semester"
           
          read sem
 
          echo " Enter the contact no"
          
          read cno


          similar=`grep -c "$rno" dbms`

          if [ $similar -eq 1 ]

          then

          echo " The entered roll no. violates the primary key constraint on roll no "

          else

          echo " $rno $name $branch $sem $cno " | cat >> dbms

          echo " The data has been added "

          fi

          ;;

        2)echo " The content of file is:"
                                
            echo "Student Details"          
            echo "Roll_No Name Branch Semester Contact_No "
            cat dbms

         ;;

        3)echo " Enter the word you want to search from the file "

          read word

          search=` grep -c -i "$word" dbms `

          if [ $search -eq 0 ]

          then

          echo " no such roll no. exist in the file "

          else

          grep -i "$word" dbms

          fi

          ;;


        4)echo " Enter The Roll No which wii be modified : "

          read rno

          search=` grep -c -i "$word" dbms `

          if [ $search -eq 0 ]

          then

          echo " no such roll no. exist in the file "

          else

          grep -v "$rno" dbms > temp

          mv temp dbms

          echo " Enter the roll no "

          read rno

          echo " Enter the name "

          read name

          echo " Enter the branch "

          read branch
	
       	  echo " Enter the Semester"
           
          read sem
 
          echo " Enter the contact no"
          
          read cno

          similar=`grep -c "$rno" dbms`

          if [ $similar -eq 1 ]

          then

          echo " The entered roll no. violates the primary key constraint on roll no "

          else

          echo " $rno $name $branch $sem $cno " | cat >> dbms

          echo " The data has been modified "

          fi

          fi

          ;;

        5)echo " Enter The Roll No which wii be deleted : "

          read rno

          search=` grep -c -i "$word" dbms `

          if [ $search -eq 0 ]

          then

          echo " no such roll no. exist in the file "

          else

          grep -v "$rno" dbms > temp

          mv temp dbms

          echo " The data has been deleted "

          fi

          ;;

        6)exit;

          ;;

esac

 

done
