import math
import time

begin = time.time()

def sundaram3(max_n):
    numbers = range(3, max_n+1, 2)
    half = (max_n)//2
    initial = 4

    for step in xrange(3, max_n+1, 2):
        for i in xrange(initial, half, step):
            numbers[i-1] = 0
        initial += 2*(step+1)

        if initial > half:
            return [2] + filter(None, numbers)

K=100000000
primes = sundaram3(K)


def is_prime(n):
  if n%3 == 0: return False
  r = int(n**0.5)
  f = 5
  while f <= r:
    if n%f == 0: return False
    if n%(f+2) == 0: return False
    f +=6
  return True

deja_vu={k:v for (k,v) in zip(primes, [True]*K)}

def is_prime_vu(n):
    if n == 2 or n == 3 : return True
    if n%2 == 0: return False
    if n < 9: return True
    if deja_vu.has_key(n):
        return deja_vu[n]
    elif n <= K:
        return False
    else:
        p=is_prime(n)
        if p:
             deja_vu[n]=p
        return p

def divisorGenerator(n):
    for i in xrange(1, int(math.sqrt(n) + 1)):
        if n % i == 0:
            yield i
            yield  n / i

s=0
N = 100000000
for x in xrange(N+1):
    if all(is_prime_vu(d+x/d) for d in divisorGenerator(x)):
        s+=x

    if (x%100000==1):
            print x

print s,time.time() - begin