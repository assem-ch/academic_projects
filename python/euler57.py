#!/usr/bin/python3

from fractions import Fraction
from math import log10


nb_digits = lambda x: int(log10(x))+1

sqrt2,cnt,N = 1, 0, 1001

for i in range(1, N):
    sqrt2 =  Fraction(1, (1+sqrt2)) + 1
    if nb_digits(sqrt2.numerator) > nb_digits(sqrt2.denominator):
        cnt +=1

print("count is", cnt)