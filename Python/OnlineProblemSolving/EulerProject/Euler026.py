from decimal import Decimal as D
from decimal import *
getcontext().prec = 1000
series = []

for d in xrange(1, 1000):
    x = D(1)/D(d);
    x -= int(x)
    repeated = 0
    serie = 0
    history = []

    for i in xrange(1000):
        if x == 0:
            break
        x *= 10
        c = int(x)
        history.insert(0, c)
        x -= c
    
    for r in xrange(1,1000):
        if reduce(lambda x,y: x and y,  [ history[r*i:r*i+r] == history[r*i+r:r*i+2 * r] if r*i+2*r < 1000 else history[r*i:r*i+r - (r*i+2 * r - 1000)] == history[r*i+r:1000]  for i in xrange(999/r )] ):
            if 499 <= r < 999:
                print d,r, ",",
            break;

