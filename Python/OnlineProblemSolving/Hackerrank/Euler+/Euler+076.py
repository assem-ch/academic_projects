# Enter your code here. Read input from STDIN. Print output to STDOUT

for T in xrange(input()):
    N = input()
    target = N
    coins = xrange(1,N)
    ways = [1]+[0]*target
    for coin in coins:
        for i in range(coin,target+1):
            ways[i]+=ways[i-coin]%(1000000007)
    print(ways[target]%(1000000007))