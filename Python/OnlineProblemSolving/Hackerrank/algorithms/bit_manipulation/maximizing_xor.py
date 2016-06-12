#!/bin/python

def  maxXor( l,  r):
    max_k = -1
    for i in xrange(l,r+1):
        for j in xrange(l,r+1):
            k = i ^ j
            if k > max_k:
                max_k = k
    return max_k

_l = int(raw_input());


_r = int(raw_input());

res = maxXor(_l, _r);
print(res)