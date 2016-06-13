from math import sqrt

i = 1

min_diff = 99999999999999999

while i < 10000:
    for j in xrange(1,i):
        S = (3 * i * i + 3 * j * j -i -j)/2.0
        D = (3 * i * i - 3 * j * j -i +j)/2.0
        if i == 7 and j == 4:
            print S,D
        if not S.is_integer() or not D.is_integer():
            continue
        is_penta = lambda x:  ((1 + sqrt(1+24 * x))/6.0).is_integer()
        if i == 7 and j == 4:
            print is_penta(S),is_penta(D)
        if not (is_penta(S) and is_penta(D)):
            continue
        else:
            print "bingo", D, i,j
            if min_diff > D:
                min_diff = D
            
    i+=1

print min_diff