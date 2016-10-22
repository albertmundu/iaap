#!/bin/bash

CHOICE=$(whiptail --title "Check List" --checklist \
        "Choose something" 20 78 10 \
        "Apple" "Rs. 100" ON \
        "Mango" "Rs. 70" OFF \
        3>&1 1>&2 2>&3
        )

echo $CHOICE
