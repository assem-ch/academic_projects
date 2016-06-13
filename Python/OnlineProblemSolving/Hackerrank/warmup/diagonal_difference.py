N = input()
s1 = 0
s2 = 0
for i in xrange(N):
    line = map(int, raw_input().split())
    s1 += line[i]
    s2 += line[N-i-1]

print abs(s1-s2)