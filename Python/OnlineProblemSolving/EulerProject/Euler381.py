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

def S(p):
    return (((p*(p-1)) - (p/2*(p/2-1)))/2)%p;

ss = 0
for p in sundaram3(100000000):
    if p < 5:
        continue
    ss += S(p)

print ss, time.time() - begin