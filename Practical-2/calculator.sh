echo "SHELL CALCULATOR"
echo "Enter The Operands"
read a
read b
echo "Press 1:Add ; 2:Sub ; 3:Mul ; 4:Div"
read ch
echo "ANS IS"
case $ch in
1)echo "$a+$b"|bc;; #or# #ans= `expr $a + $b`# #blank spaces are important#
2)echo "$a-$b"|bc;;
3)echo "$a*$b"|bc;;
4)echo "$a/$b"|bc;;
*)echo "INVALID KEYWORD";;
esac

