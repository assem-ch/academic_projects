from fractions import gcd

def sbtree(n, d):
    ufrac = [0, 1]
    lfrac = [1, 0]
    frac = [1, 1]
    bfrac = [1, 2]
    while(frac[0] * d != frac[1] * n):
        if(frac[0] * d > frac[1] * n):
            # push it towards lfrac
            lfrac[0] = frac[0]
            lfrac[1] = frac[1]
            bfrac[0] = bfrac[0] * 2 - 1
        elif(frac[0] * d < frac[1] * n):
            # push it towards ufrac
            ufrac[0] = frac[0]
            ufrac[1] = frac[1]
            bfrac[0] = bfrac[0] * 2 + 1
        frac[0] = ufrac[0] + lfrac[0]
        frac[1] = ufrac[1] + lfrac[1]
        bfrac[1] *= 2
    return ufrac

for t in xrange(input()):
    a,b,N = map(int, raw_input().split())

    n,d=sbtree(a,b)

    p =(N-d)/b
    r=p*a+n
    s=p*b+d
    print r,s