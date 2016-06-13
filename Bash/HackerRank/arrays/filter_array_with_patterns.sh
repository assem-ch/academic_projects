#!/usr/bin/env bash


LOOP=1
for((i = 0; $LOOP; i++));
do
    read k || LOOP=0;
    if [[ $k == *"a"* || $k == *"A"* ]];
    then :
    else a[$i]=$k;
    fi;
done;
echo ${a[@]}