#!/usr/bin/env bash

read x
read y
if (( $x == $y)); then echo "X is equal to Y";
elif (( $x < $y)); then echo "X is less than Y ";
else echo "X is greater than Y";
fi;