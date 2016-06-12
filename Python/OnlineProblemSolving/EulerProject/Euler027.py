import time

start = time.time()


def Primary(X):
    if X== 1 or X == 2:
        return True
    #print (2 ** X - 2) % X
    if (2 << X - 2) % X == 1:
        for i in xrange(2,X):
            if X%i == 0:
                return False
            if  X/i < i:
                return True
    else:
        return False



max_n, max_a,max_b = 0, None, None

for a in xrange(-999,1000):
   for b in xrange(-999,1000):
       n = 0
       while (True):
           X = n ** 2 + a * n + b
           if X<1 or not Primary(X):
               break
           n+=1

       if max_n < n:
           max_n, max_a,max_b = n, a, b

end = time.time()


print max_n, max_a, max_b
print end - start