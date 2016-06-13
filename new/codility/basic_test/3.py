#!/bin/python

"""

Task #3:

You need to divide and conquer this. Try to understand that the matrix:

| 1 1  |  
| 1 0 | raised to the nth power will have your answer, then realize that you can recursively divide the problem into smaller one reaching a complexity of log(n)

"""

def solution(N):
    M = 1000000
    a, b, c = 1, 1, 0
    for r in bin(N)[3:]:
        t = b*b
        a, b, c = (a*a+t)%M, ((a+c)*b)%M, (t+c*c)%M
        if r == '1':
            a, b, c = a+b, a, b
    return b % M
    
print solution(0)

M = 1000000
    
def mul(A, B):
    a, b, c = A
    d, e, f = B
    return (a*d + b*e)%M, (a*e + b*f)%M, (b*e + c*f)%M

def pow(A, n):
    if n == 1:     return A
    if n & 1 == 0: return pow(mul(A, A), n//2)
    else:          return mul(A, pow(mul(A, A), (n-1)//2))

def solution(n):
    if n < 2: return n
    return pow((1,1,0), n-1)[0]%M

print solution(2147483647)

assert solution(8) == 21, "Case 1 failed"
assert solution(36) == 930352, "Case 2 failed"
