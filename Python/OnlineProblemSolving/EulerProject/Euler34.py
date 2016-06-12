import math
is_curious = lambda x: x == sum(map(math.factorial, map(int, str(x))))
filter(is_curious, [x for x in xrange(3,1000000)])
