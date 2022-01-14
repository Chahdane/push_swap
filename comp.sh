#!bin/bash
make
read a b c d e
./push_swap $a $b $c $d $e
LINES=$(./push_swap $a $b $c $d $e | wc -l)
MOVES=`expr $LINES - 1`
printf "\nTOTAL MOVES : ${MOVES}\n\n"