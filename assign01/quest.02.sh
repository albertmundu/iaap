#!/bin/bash


a=$1
b=$2
c=$3

if [[ $a -ge $b && $a -ge $c ]]; then
    printf "%d" "$a"
elif [[ $b -ge $a && $b -ge $c ]]; then
    printf "%d" "$b"
elif [[ $c -ge $a && $c -ge $b ]];then
    printf "%d" "$c"
fi
