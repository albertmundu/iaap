#!/bin/bash

#@ Description: To see current date, time, username and current directory

cdate=$(date +"%D")
ctime=$(date +"%H:%M:%S")
cdir=$PWD

echo $cdate
echo $ctime
echo $cdir

