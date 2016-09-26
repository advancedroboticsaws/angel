#!/bin/bash          
#
# Script to relay the angelbot/cmd_vel topic 
# 
# Weber-Hsu
# Mon 26 Sep 2016 
#
# 

function showHelp(){
    echo 
    echo "This script can relay the topic "angelbot/cmd_vel" after launch the angelbot base roslaunch file"
 }

if [ "$1" = "-h" ]; then
    showHelp
else 
    echo "now relay topic"
    echo "topic angelbot/cmd_vel relayed to andbot/cmd_vel for telep app"
    rosrun topic_tools relay andbot/cmd_vel angelbot/cmd_vel
fi
