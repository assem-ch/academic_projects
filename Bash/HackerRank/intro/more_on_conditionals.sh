#!/usr/bin/env bash

read x
read y
read z
if [[ (($x == $y)) &&  (($y == $z)) ]]; then echo "EQUILATERAL";
elif [[ (($x < $y)) &&  (($y < $z)) ]];  then echo "SCALENE";
else echo "ISOSCELES";
fi