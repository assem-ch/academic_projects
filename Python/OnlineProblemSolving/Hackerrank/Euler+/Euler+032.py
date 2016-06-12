N = input()


#since there is only 9 cases, I went with precalculation
pre_calculated = {1 : 0 ,
2 : 0 ,
3 : 0 ,
4 : 12 ,
5 : 52 ,
6 : 162 ,
7 : 0 ,
8 : 13458,
9 : 45228
}

print pre_calculated[N]
exit()

## code of calculation
MIRROR = "123456789"[0:N]
LIMIT = 987654321%(10**N)
pandigit = lambda x: x == MIRROR

a = 1
l = set()

while True:
    for b in xrange(1,a):
        c = a*b
        n = str(a)+str(b)+str(c)
        if len(n) > N:
            break
        if "0" not in n and pandigit("".join(sorted(n))):
            l.add(c)
    a+=1
    if a > LIMIT:
        break

print sum(l)


