#!/usr/bin/env bash

LOOP=1
read k || LOOP=0;
for((i = 0; LOOP; i++));
do
echo ${k:2:1};
read k || LOOP=0;
done;