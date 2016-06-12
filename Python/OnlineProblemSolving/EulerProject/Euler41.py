
import math
def is_prime(n):
    if n % 2 == 0 and n > 2: 
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True


import itertools

s = "987654321" 

while (s):
    print s
    for x in itertools.permutations(s):
        n = int("".join(x))
        if is_prime(n):
            print "prime and pand==>",n
            s="1"; break

    s = s[1:]
