#!/bin/bash

make

if [ $? -ne 0 ]
then
	printf "\nCOMPILATION ERROR\n"
	exit
fi

ARG=$(./rand.sh $1 $2)

printf "\nUNSORTED t_stack: \n${ARG}\n"

MOVES=$(./push_swap $ARG)

printf "\n${MOVES}\n\n"

RED="\e[31m"
GREEN="\e[32m"
ENDCOLOR="\e[0m"

if [ -z "$MOVES" ] ; then
	OK=$(echo -n "" | ./checker_Mac $ARG 2>&1)
else
	OK=$(echo "${MOVES}" | ./checker_Mac $ARG 2>&1)
fi

if [ "$OK" = "OK" ] ; then
	printf "${GREEN}${OK}${ENDCOLOR}\n"
else
	printf "${RED}${OK}${ENDCOLOR}\n"
fi


WC=$(echo "$MOVES" | wc -l)

if [ -z "$MOVES" ] ; then
	printf "\nMOVES: 		0\n\n"
else
	printf "\nMOVES: ${WC}\n\n"
fi