import math
for i in xrange(input()):
    N = input()
    phi = (1+math.sqrt(5))/2
    print int(math.ceil((N + math.log10(5)/2 - 1)/math.log10(phi)))