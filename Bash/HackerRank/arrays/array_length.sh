#!/usr/bin/env bash

LOOP=1
read k || LOOP=0
for((i = 0; $LOOP; i++));
do
    a[$i]=$k;
    read k || LOOP=0;
done;
echo ${#a[@]}