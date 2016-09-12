#!/bin/bash

fact(){
    local num=$1
    if [ $num -eq 0 ]; then
        ret=1
    else
        temp=$((num-1))
        #fact $temp
        #ret=$((num*$?))
        ret=$((num * $(fact temp)))
    fi
    return $ret
}


fact 10

echo $ret
