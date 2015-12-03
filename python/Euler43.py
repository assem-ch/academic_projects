import time


start = time.time()

from itertools import permutations

s=0

for p in permutations("1234567890"):

    if not any([int(p[7]+p[8]+p[9]) % 17, int(p[6]+p[7]+p[8]) % 13, int(p[5]+p[6]+p[7]) % 11, int(p[4]+p[5]+p[6]) % 7,  int(p[3]+p[4]+p[5]) % 5, int(p[2]+p[3]+p[4]) % 3,  int(p[1]+p[2]+p[3]) % 2,  ]):
        print "bingo", "".join(p)
        s+= int("".join(p))
        
print s

end = time.time()

print end - start
