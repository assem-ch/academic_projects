#!/usr/bin/env bash

LOOP=1
for((i = 0; $LOOP; i++));
do
    read k || LOOP=0;
    a[$i]=$k;
done;
echo ${a[3]}