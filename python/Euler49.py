import math
def is_prime(n):
    if n % 2 == 0 and n > 2: 
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

from collections import Counter
from itertools import permutations, product

for i in xrange(1001,9999):
    if not is_prime(i):
        continue
    l = sorted(filter(is_prime, map(lambda x: int("".join(x)), set(permutations(str(i))))))
    if len(l)<3:
        continue
    d =  filter(lambda y: y[0]>0,map(lambda x: (x[1] - x[0], x[1], x[0]), product(l,l)))
    for e in d:
        if e[2] == i and e[1]+e[0] in l:
            print "bingo", "{0}{1}{2}".format(i, e[1], e[1] + e[0]), e[0]
            #print l
