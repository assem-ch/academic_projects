for N in xrange(1,10):
    MIRROR = "123456789"[0:N]
    LIMIT = 987654321%(10**N)

    if N==9:
        print 45228
    elif N==8:
        print 13458
        exit()

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

    print N,":",sum(l),","
