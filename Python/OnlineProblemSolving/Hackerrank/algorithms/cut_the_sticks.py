N = input()
S = map(int, raw_input().split())

while(S):
    print len(S)
    m = min(S)
    S = filter(lambda x: x!=0, map(lambda x: x-m, S))