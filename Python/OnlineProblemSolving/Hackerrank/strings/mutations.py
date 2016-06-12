s = raw_input()
i, c = raw_input().split()
s = list(s)
s[int(i)]=c
print "".join(s)