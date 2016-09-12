#!/bin/bash

COLOR=$(whiptail --inputbox "Choose Color" 6 48 \
        Blue --title "Color Chooser" \
        3>&1 1>&2 2>&3
       )

clear
ping -c 1 -w 1 $COLOR >/dev/null
if [ $? -eq 0 ]; then
whiptail --title "message" --msgbox $COLOR" is active" 10 40
else
whiptail --title "message" --msgbox $COLOR" is not active" 10 40
fi

exit 0
