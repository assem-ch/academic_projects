import time
import math

begin = time.time()
reverse=lambda x: int(str(x)[::-1])

def odd(x):
    while(x>0):
        if (x%10)%2 == 0:
            return False
        x /= 10
    return True

cpt=0
# I guessed 1E8 gives same result as 1E9, and that was true: #20, 120 , 720, 720, 18720, 18720, 608720,608720
# so I used 1E8 instead
for a in xrange(int(1E8)):
    if a%10==0:
        continue
    b = reverse(a)
    x = a+b
    if odd(x):
        cpt+=1
        
    if a%1000000==1:
        print a

print cpt, time.time() - begin
