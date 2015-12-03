from itertools import product
from math import sqrt
import time
start_time = time.time()


def som(A): #should be optimized for larger numbers
    S=0
    for i in xrange(1, A):
        if A % i == 0:
           S+=i
    return S

Abun =[]

for x in xrange(12, 28123):
    if som(x) > x:
        Abun.append(x)

sumofabun = map(lambda x: x[0]+x[1], product(Abun,Abun))

l  = set(range(28124)) - set(sumofabun)

s = sum(l)


print s

print("--- %s seconds ---" % (time.time() - start_time))