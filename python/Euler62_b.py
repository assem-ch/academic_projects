from itertools import permutations

import time

start = time.time()

a = 0
cubes_counters ={}
cubes = {}

while(True):
    a+=1
    b = str(sorted(str(a ** 3)))
    if cubes_counters.has_key(b):
        cubes_counters[b]+=1
        if cubes_counters[b] >= 5:
            print "bingo", cubes[b]
            break
    else:
        cubes_counters[b] = 1
        cubes[b] = a ** 3

end = time.time()

print end - start