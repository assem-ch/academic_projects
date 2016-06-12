

F = open("p022_names.txt")

exec  "L = sorted([" + F.read() + "])"

Value = lambda s: sum(map(lambda x: ord(x) - 64, s))

Total = sum([Value(L[i]) * (i+1) for i in xrange(len(L))]) 

print Total