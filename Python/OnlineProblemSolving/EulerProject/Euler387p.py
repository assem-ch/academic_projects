
from time import time,sleep
import gmpy2



from multiprocessing import Pool, Queue,Manager


def checker(x):
    x,ns = x
    if x%3 ==0  or x% 5 ==0 or x%7 ==0:
       return False
    if check(x):
        ns.cpt+=1
        ns.s+=x
        return True


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

global cpt,s
cpt = s = 0
N = 10000
mil = 1000
p = Pool(processes=5)
m =  Manager()
ns = m.Namespace()
ns.s = s
ns.cpt = cpt
ns.mil = mil

def checking_interval(start):

    for x in xrange(start,start+mil,2):
        checker(x)

for i in xrange(0, N/mil - 5, 5):
    p.map(checking_interval, [ 11+i*mil, 11+(i+1)*mil, 11+(i+2)*mil,11+(i+3)*mil, 11+(i+4)*mil])



print "count:%d, sum: %d" % (ns.cpt,ns.s)
print "time:", time()-start


