
import time


start = time.time()


def sum_sqr_digits(x):
    if x != 0:
        return (x % 10) ** 2 + sum_sqr_digits(x/10)
    else:
        return 0

cpt = 0

for i in xrange(1,10000000):
    x = i
    while (x != 89 and x!=1):
        x = sum_sqr_digits(x)
    
    if (x == 89):
        cpt+=1
        print i
    
    
end = time.time()

print cpt
print end - start