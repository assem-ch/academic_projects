N = int(raw_input())

S = raw_input()

M = int(raw_input())

Rotate = lambda s,p: s[p:] + s[:p]

for cpt in xrange(M):
    L, R, K = map(int, raw_input().split())
    l = R - L + 1
    new_S = Rotate(S[L-1:R], l - K% l)
    if L != 1:
        new_S = S[:L-1] + new_S
    if R != N:
        new_S += S[R:]

    S = new_S

print S