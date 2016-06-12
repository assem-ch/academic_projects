#!/usr/bin/py
# Head ends here
from collections import Counter

def pairs(a,k):
    answer = 0
    c = Counter()
    for x in a:
        if c[x+k] or c[x-k]:
            answer+=c[x+k]+c[x-k]
        c[x]=1
    return answer

# Tail starts here
if __name__ == '__main__':
    a = map(int, raw_input().strip().split(" "))
    _a_size=a[0]
    _k=a[1]
    b = map(int, raw_input().strip().split(" "))
    print pairs(b,_k)
