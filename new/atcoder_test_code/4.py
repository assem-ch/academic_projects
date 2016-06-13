from itertools import permutations
from operator import add

N = int(raw_input())

A_flexible = []
A_fixed = []

S = 0

for cpt in xrange(N):
    a, d = map(int, raw_input().split())
    if d == -1:
        A_flexible.append(a)
    else:
        A_fixed.append((a,d))


for X in permutations(A_flexible):
    X = list(X)
    for E in A_fixed:
        X.insert(E[1]-1, E[0])
    
    s = reduce(add,map(lambda x: x[0] * x[1], zip(X[:-1],X[1:])))
    
    if s > S:
        S = s

print S