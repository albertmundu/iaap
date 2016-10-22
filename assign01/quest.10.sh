#!/bin/bash

read a
read b
c=`echo $a + $b | bc` 

printf "%f\n" "$c"

