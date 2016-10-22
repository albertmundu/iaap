#!/bin/bash


year=$1

if [[ $year%4 -eq 0 && $year%100 -ne 0 || $year%400 -eq 0 ]];then
    printf "Leap year\n"
else
    printf "Not leap year\n"
fi
