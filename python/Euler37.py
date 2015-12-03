import math
def is_prime(n):
    if n % 2 == 0 and n > 2: 
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True




left_part = lambda x:  -1 if len(str(x)) == 1 else  int(str(x)[:-1])
right_part = lambda x: -1 if len(str(x)) == 1 else int(str(x)[1:])

def left_special(x):
    if x == 1:
        return False
    if x in [-1,2,3,5,7]:
        return True
    #print x,"==>", is_prime(x), "left>", left_part(x), "right>",right_part(x)
    return (is_prime(x) and left_special(left_part(x)))

def right_special(x):
    if x == 1:
        return False
    if x in [-1, 2,3,5,7]:
        return True
    #print x,"==>", is_prime(x), "left>", left_part(x), "right>",right_part(x)
    return (is_prime(x) and right_special(right_part(x)))

def special(x):
    return right_special(x) and left_special(x)


print sum(filter(special, xrange(10, 1000000)))