import math
def is_prime(n):
    if n % 2 == 0 and n > 2: 
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

def Get_Rotations(Number):
    Rotations = []
    x = 0
    Number = list(str(Number))
    while x < len(Number):
        Number.insert(0,Number.pop())
        Rotations.append(int("".join(Number)))
        x += 1
    return Rotations

cpt = 0;
for x in xrange(2,100):
    r = Get_Rotations(x)
    if all(map(is_prime, r)):
        print x,r
        cpt+=1

print cpt