import time

start = time.time()


print max([ sum(map(int, list(str(a ** b)))) for a in xrange(90,100) for b in xrange(90,100)])
#print max( [ sum( [ int( i ) for i in str( a ** b ) ] ) for a in xrange( 90, 100 ) for b in xrange( 90, 100 ) ] )
end = time.time()

print end - start