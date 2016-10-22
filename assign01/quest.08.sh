#!/bin/bash
count=0
for((i=0;i<4;i++));do
    for((j=0;j<=$i;j++));do
        count=$(($count+1))
        printf "%d " "$count"
    done
    printf "\n"
done
