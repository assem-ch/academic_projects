#!/bin/python

def solution2(K, A):
    n = 0
    for i in xrange(len(A)):
        v = K-A[i]
        if v == A[i]:
            n += 1
        c = A[i+1:].count(v)
        if c:
            n += 2 * c
    return n
    
from collections import Counter

def solution(k, a):
    answer = 0
    c = Counter() 
    for x in a:
        if c[k-x]:
            answer += c[k-x]*2
        if x == k/2.0:
            answer+=1
        c[x]+=1
    return answer
    

    


assert solution(6,[1,8,-3,0,1,3,-2,4,5]) == 7, "Case 1 failed"
assert solution(6,[1]) == 0, "Case 2 failed"
assert solution(4,[8,-4, 2]) == 3, "Case 3 failed"
assert solution(6,[3,2, 3]) == 4, "Case 4 failed"