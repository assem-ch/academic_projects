#!/bin/python


from fractions import Fraction
from math import log

# read the input
f=open("in")
T=int(f.readline())


output=""
for case in xrange(T):
    P,Q = f.readline().split("/")	
    frac = Fraction(int(P),int(Q))
    P = frac.numerator
    Q = frac.denominator
    possible = (not 1099511627776L % Q) and  P/Q <= 1 and P/Q >=0 
    minimal = "impossible"
    if possible:
	level = int(log(Q,2))
	print level
	for i in range(level, 0,-1):
	     diff = level - i + 1
	     other_val = P * 2 - Q 
	     print other_val,"*"
	     if P * 2 >= Q and other_val in xrange(2 ** i):
		 minimal = diff;
		 break 
	     Q = Q / 2	
    output+="Case #%d: %s\n" % (case+1,str(minimal))
    #f.readline()
    
    
    
    
OUTPUT=open("out","w")
OUTPUT.write(output)
print output
print "done"

