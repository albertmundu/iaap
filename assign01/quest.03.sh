#!/bin/bash

num=$1

if (($num&1)); then
    printf "%d is odd\n" "$num"
else
    printf "%d is even\n" "$num"
fi
