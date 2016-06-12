from math import sqrt

def som(A): #should be optimized for larger numbers
    S = 0
    for i in xrange(1, A):
        if A % i == 0:
            S+=i;

    return S

Amicable = []

for A in xrange(1, 10001):
    if A not in Amicable:
        SA = som(A)
        print A,SA
        if SA < 10000 and SA != A:
            if som(SA) == A:
                Amicable.append(A)
                Amicable.append(SA)

print Amicable