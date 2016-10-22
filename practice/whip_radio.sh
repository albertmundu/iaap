#!/bin/bash
    CHOICE=$(whiptail --title "Radio List" --radiolist \
            "Choose user's permissions" 20 78 4 \
            "Apple" "Allow connections to other hosts" ON \
            "Bat" "Allow connections from other hosts" OFF \
            "Cat" "Allow mounting of local devices" OFF \
            "Dog" "Allow mounting of remote devices" OFF \
            3>&1 1>&2 2>&3 \
            )
{
    for((i=0;i<=100;i++));do
        sleep 1
        echo $i
    done
} | whiptail --gauge "Please wait ... " 6 50 0

clear
echo "Choice(s): $CHOICE"

exit 0
