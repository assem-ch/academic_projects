N = input()
S1 = map(int, raw_input().split())
M = input()
S2 = map(int, raw_input().split())

S3 = sorted(set(S1) ^ set(S2))
for x in S3:
    print x