balls = range(1,9)

N, K = map(int, raw_input().split())

OP = []
for j in xrange(N):
    OP.append( map(int, raw_input().split()))

for i in xrange(K):
    for e in OP:
        balls[e[0]-1], balls[e[1]-1] = balls[e[1]-1], balls[e[0]-1]


print " ".join(map(str,balls))