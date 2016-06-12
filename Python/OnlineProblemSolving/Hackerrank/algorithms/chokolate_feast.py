T = int(raw_input())
for i in range (0,T):
    N,C,M = [int(x) for x in raw_input().split(' ')]
    
    answer = N/C
    wrappers = N/C
    while(wrappers >=M):
        answer+=wrappers/M
        wrappers= wrappers%M + wrappers/M

    print answer