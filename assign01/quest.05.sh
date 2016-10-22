#!/bin/bash

read num

if [[ $num -lt 0 ]]; then
    printf "Negative\n"
else
    printf "Positive\n"
fi

