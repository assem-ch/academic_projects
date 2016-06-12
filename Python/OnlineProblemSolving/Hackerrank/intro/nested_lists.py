N = input()

d = {}

for i in xrange(N):
    name = raw_input()
    mark = float(raw_input())
    if mark in d:
        d[mark].append(name)
    else:
        d[mark]=[name]

last = -1
for k in sorted(d.keys()):
    if k != last and -1 != last:
        for v in sorted(d[k]):
            print v
        break
    else:
        last = k
