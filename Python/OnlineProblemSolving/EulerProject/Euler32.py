

pandigit = lambda x: x == "123456789"


a = 1
l = set()

while True:
    for b in xrange(1,a):
        c = a*b
        n = str(a)+str(b)+str(c)
        if len(n) > 9:
            break
        if "0" not in n and pandigit("".join(sorted(n))):
            l.add(c)
            print a,b,c
            print len(l), l
    a+=1
    if a > 987654321:
        break
