series = []

for d in xrange(1, 1000):
    x = 1.0/d;
    x = x - int(x)
    repeated = 0
    serie = 0
    history = []

    for i in xrange(15):
        x *= 10
        c = int(x)
        history.insert(0, c)
        x = x - c
    
    for r in xrange(1,15):
        if reduce(lambda x,y: x and y,  [ history[r*i:r*i+r] == history[r*i+r:r*i+2 * r] if r*i+2*r < 15 else history[r*i:r*i+r - (r*i+2 * r - 15)] == history[r*i+r:15]  for i in xrange(14/r )] ):
            if r >= 9 and r <12:
                print d, r, 1.0/d
            break;

# 81 9 0.0123456790123
# 451 10 0.00221729490022

