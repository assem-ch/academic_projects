import time
import math

start = time.time()

def is_prime(n):
    if n % 2 == 0 and n > 2: 
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

n =1
nb_total = 1
nb_primes = 0

while True:
    n +=2
    nb_total += 4
    nb_primes += len(filter(is_prime, [n*n, n*n - 2 * n + 2, n*n - n + 1, n * n - 3 * n + 3 ]))
    ratio = float(nb_primes)/nb_total

    if  ratio < 0.1:
        print "under", n, ratio
        break

end = time.time()

print end - start