from math import sqrt


is_penta = lambda x:  ((1 + sqrt(1+24 * x))/6.0).is_integer()
is_hexa = lambda x:  ((1 + sqrt(1+8 * x))/4.0).is_integer()

n = 286

while True:
    t = n * ( n +1) / 2
    
    if is_penta(t) and is_hexa(t):
        print "bingo", t
        break
    n+=1
