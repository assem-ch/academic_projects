
import time

start = time.time()

a = 1

while True:
    a_s = sorted(str(a))
    #print a
    broke = False
    for x in xrange(2,6):
        if sorted(str(a *x)) != a_s:
            a+=1
            broke = True
            break
    if not broke:
        print "bingo", a
        break

end = time.time()

print "time", end - start