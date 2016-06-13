import math
for x in xrange(input()):
    N, M = map(int,raw_input().split())
    print (math.factorial(N + M - 1) / (math.factorial(N) * math.factorial(M - 1))) % 1000000007