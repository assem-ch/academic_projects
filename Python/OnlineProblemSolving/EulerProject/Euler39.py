import math
possi =  [0] * 1000

for a in xrange(1,1000):
    for b in xrange(1,1000-a):
        p = a+b+math.sqrt(a*a+b*b)

        if a*a + b*b != (round(p) - a -b)**2:
            continue
        if p > 1000:
            break
        print p
        possi[int(round(p))-1]+=1

print possi.index(max(possi))+1
print possi