# python 3
from functools import reduce
from time import time

begin = time()
nb_to_list = lambda N: map(int, str(N))

inc = lambda L: reduce(lambda a,b: b if a <= b else 10 , L)!=10
dec = lambda L: reduce(lambda a,b: b if a >= b else -1 , L)!=-1


N = 1
nB = 0

while(True):
    l = list(nb_to_list(N))
    if inc(l) or dec(l):
        nB+=1

    if nB/N<=0.01:
        break

    N+=1

print(N) # 

end = time()

print("in time:",end - begin)