

import time




begin = time.time()

N = 1000000

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


primes = sundaram3(200)

r = 1
i = 0

while(r * primes[i]<N):

    r *= primes[i]
    i+=1


print r

end = time.time()

print ">>%5f" % (end-begin)