from __future__ import division
from math import sqrt


def sieve(limit):
    nums = range(limit+1)
    nums[1] = 0
    for n in nums:
        if n:
            for x in range(2*n, limit+1, n):
                nums[x] = 0 # counting this vs. pop
    return set(filter(None, nums))


N=50000000
K=7071
primes = sieve(7071)
primes4 = filter(lambda x: x<N, [p**4 for p in primes])
primes3 = filter(lambda x: x<N, [p**3 for p in primes])

deja_vu=set()

cpt=0
for i in primes:
    i2 = i**2
    for j in primes3:
        for k in primes4:
            number = i2 + j + k
            
            if number < N and number not in deja_vu:
                #print number, cpt
                cpt+=1
                deja_vu.add(number)

print cpt