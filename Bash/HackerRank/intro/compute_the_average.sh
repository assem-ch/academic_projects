#!/usr/bin/env bash

read T
let s=0
for ((i = 0; i < $T; i++));
do
  read x;
  let s=$(($s+$x));
done;
printf "%.3f" `echo "$s/$T" | bc -l`;