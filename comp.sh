#!/bin/bash
make
ARGS=$@
./push_swap $ARGS
LINES=$(./push_swap $ARGS | wc -l)
MOVES=$(expr $LINES - 1)
printf "\nTOTAL MOVES : ${MOVES}\n\n"
#echo "$check" | ./checker_Mac $ARGS