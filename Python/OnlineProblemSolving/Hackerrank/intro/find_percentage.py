N = input()
d={}
for i in xrange(N):
    NAME, x,y,z = raw_input().split()
    t = map(float,[x,y,z])
    d[NAME]=t

selected = raw_input()

print "{:.2f}".format(sum(d[selected])/3)