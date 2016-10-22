#!/bin/bash

read str

#rstr=`echo $str | rev`

#if [[ $str == $rstr ]];then
#    printf "palindrome\n"
#else
#    printf "not palindrome\n"
#fi

len=${#str}

for((i=0;i<$len/2;i++));do
    if [[ ${str:$i:1} == ${str:$len-1-i:1} ]];then
        status=1
    else
        status=0
        break
    fi
done

if [[ status -eq 0 ]];then
    printf "not palindrome\n"
else
    printf "palindrome\n"
fi
