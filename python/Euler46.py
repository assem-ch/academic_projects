import math
def is_prime(n):
    if n % 2 == 0 and n > 2: 
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True


for i in xrange(9,100000000,2):
    if is_prime(i):
        continue
    possible = False
    for b in xrange(1,i/2):
        a = i - 2 * b * b
        if a <=0:
            break
        if is_prime(a):
            possible = True
            break
    if not possible:
        print "bingo", i
        break
    
