N,K = map(int, raw_input().split())

def baseN(num,b,numerals="0123456789"):
    return ((num == 0) and numerals[0]) or (baseN(num // b, b, numerals).lstrip(numerals[0]) + numerals[num % b])

print sum(filter(lambda n: str(n) == str(n)[::-1] and baseN(n, K)  == baseN(n, K)[::-1], xrange(N)))