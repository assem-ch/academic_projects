from __future__ import division
from math import factorial as f


def nCr(n,r):
    return f(n) / f(r) / f(n-r)


PN = 7* (1 - (nCr(60,20)/nCr(70,20)))


print(PN)