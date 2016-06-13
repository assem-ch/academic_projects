T = int(raw_input())
N = []
max_N = 0;
for i in xrange(T):
    N.append(input())
    if N[i]>max_N:
        max_N = N[i];

primes = [ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113]
cpt = 30;
number = 117;
is_prime=True;
OBJECTIVE = max_N;

while(cpt < OBJECTIVE ):
    if (is_prime):
        for p in primes:
            if (number%p==0):
               is_prime = False
               break

    if (is_prime):
        primes.append(number)
        cpt+=1

    number +=1;
    is_prime=(2 << number - 2) % number == 1;

for k in xrange(T):
    print primes[N[k]-1]