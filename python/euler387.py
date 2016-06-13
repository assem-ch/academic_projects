
from time import time,sleep
import gmpy2
import threading
from threading import Thread,Lock
import Queue



class Checker(Thread):
   def __init__(self, val):
       Thread.__init__(self)
       self.val = val

   def run(self):
       global cpt,s
       if check(x):
           l.acquire()
           s+=x
           cpt+=1
           l.release()
           

start = time()



def sumdigits(x):
    s=0
    while(x>0):
        s+= x%10
        x//=10
    return s

def check(p):
    x = p//10
    sd = sumdigits(x)

    while(x>0):
            xx = x%sd
            if xx != 0:
                return False
            sd-= x%10 
            x//=10
    x=p//10
    if not gmpy2.is_prime(x//sumdigits(x)):
            return False
    if not gmpy2.is_prime(p):
        return False
    return True

th = []
l = Lock()
global cpt,s
cpt = s = 0
N = 10000
tour = 0
for x in xrange(11,N,2):
    if x%3 ==0  or x% 5 ==0 or x%7 ==0:
        continue
    ch = Checker(x)
    ch.start()
    #print threading.active_count()
    ch.join()
    del ch
    #th.insert(0, ch)




print "done", len(th)




l.acquire()
print "count:%d, sum: %d" % (cpt,s)
print "time:", time()-start
l.release()


