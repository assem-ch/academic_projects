

def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors



a = 5
set_prev = set([2]) 
set_prev2 = set([3]) 
set_prev3 = set([2]) 

while True:
    set_current = set(prime_factors(a))
    print a, set_current, set_prev, set_prev2, set_prev3
    if all(map(lambda x: x == 4,[len(set_current), len(set_prev),  len(set_prev2),  len(set_prev3)])):
        print "bingo",a -3
        break
    
    set_prev3 = set_prev2
    set_prev2 = set_prev
    set_prev = set_current

    a+=1