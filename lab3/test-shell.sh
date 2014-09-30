#!/bin/bash

# Check cmd,if ok return 1 else return 0
CheckCmdRun()
{
    cmd=${1}"\nexit"
    result=$(echo -e ${cmd}|./demo)
    
    echo ${result} | grep "Error command!" >/dev/null
    if [ $? == 1 ]
    then
        echo "Cmd '"${1}"' running ok"
    else
        echo "Cmd '"${1}"' running fail"
    fi
}

# Testcase
CheckCmdRun "ls"

CheckCmdRun "ustc"
