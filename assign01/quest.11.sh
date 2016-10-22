#!/bin/bash
count=0
while [ 1 ];do
    if (($count&1)); then
        echo -e -n "\e[01;33m"
    else
        echo -e -n "\e[01;31m"
    fi
    echo -e -n "Hello World\r"
    echo -e -n "\e[0m"
    count=$(($count+1))
done

