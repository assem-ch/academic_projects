from __future__ import division
from itertools import combinations_with_replacement

N = input()
s=0
for i in xrange(N):
    ball = input()
    s+=ball

print s/2