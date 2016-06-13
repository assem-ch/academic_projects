#Project Euler Problem 243


primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
ratio = 15499/94744.0    # the decimal point forces a float value

def denom(ratio):
    d, s = 1, 1
    for p in primes:
        d *= p
        s *= p-1
        for i in range(2, p):
            if s*i / (d*i - 1.0) < ratio:
                return d*i
    return "Please buy more primes!"

print 'Project Euler 243 Solution =', denom(ratio)