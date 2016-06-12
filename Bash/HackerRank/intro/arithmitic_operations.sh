#!/usr/bin/env bash

read k
printf "%.3f" $(echo "$k"|bc -l)