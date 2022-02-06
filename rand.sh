#!/bin/bash

#$1: number of generated numbers
#$2: range of 0 to $2-1

i=0;
while [ $i -lt $1 ]
do
	rand[i]=$(( $RANDOM % $2))
	j=0
	while [ $j -le $(($i-1)) ]
	do
		if [ ${rand[$i]} -eq ${rand[$j]} ] 
		then
			((i--))
			break
		fi
		((j++))
	done
	((i++))
done

for i in ${rand[@]}
do
	echo -n "$i "
done
