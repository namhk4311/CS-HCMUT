#!/usr/bin/bash
# compare.sh

read -p "Enter X: " x
read -p "Enter Y: " y

if [ $x -gt $y ]
then
	echo X is greater than Y
elif [ $x -lt $y ]
then
	echo X is less than Y
elif [ $x -eq $y ]
then
	echo X is equal to Y
fi
