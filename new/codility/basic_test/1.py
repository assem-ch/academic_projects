#!/bin/python

def solution(A):
    i = 0
    j = 0
    L = len(A)
    visited = set()
    while(0 <= i < L): #fix limit
        if i in visited:
            return -1
        visited.add(i)
        j += 1
        i += A[i]
    return j

assert solution([1,1,1,1,1]) == 5, "Case 1 failed" 
assert solution([2,3,-1,1,3]) == 4, "Case 2 failed" 
assert solution([1,1,-1,1]) == -1, "Case 4 failed"
