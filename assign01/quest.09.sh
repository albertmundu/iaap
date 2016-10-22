#!/bin/bash

read num

a=0
b=1
for((;$a<$num;));do
    printf "%d " "$a"
    c=$(($a+$b))
    a=$b
    b=$c
done
printf "\n"
