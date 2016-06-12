from fractions import gcd


for t in xrange(input()):
    a,b,x,y = map(int, raw_input().split())
    if gcd(a,b) == gcd(x,y):
        print "YES"
    else:
        print "NO"