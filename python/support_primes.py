def primes1(n):
    """ Returns  a list of primes < n """
    sieve = [True] * (n/2)
    for i in xrange(3,int(n**0.5)+1,2):
        if sieve[i/2]:
            sieve[i*i/2::i] = [False] * ((n-i*i-1)/(2*i)+1)
    yield 2
    for i in xrange(1,n/2):
        if sieve[i]:
            yield 2*i+1 