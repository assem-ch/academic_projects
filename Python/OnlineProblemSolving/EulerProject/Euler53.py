from math import factorial

C = lambda n,r: factorial(n)/ (factorial(r) * factorial(n-r))

cpt=0

for n in xrange(1,101):
    for r in xrange(1, n+1):
        if C(n,r) >= 1e6:
            cpt+=1


print cpt