import time

start = time.time()

n = 1001

s = 1 

s+= sum([x*x for x in xrange(3, n+1, 2)])
s+= sum([x*x + 1 for x in xrange(2, n+1, 2)])
s+= sum([x*x - x + 1  for x in xrange(2, n+1, 1)])

# s = N/2 - 1 + N - N*(N+1)/2 + 2*(N*(N+1)*(2*N+1) / 6)

print s

end = time.time()

print end - start