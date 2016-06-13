a = raw_input()
b = raw_input()

count = 0
for i in xrange(len(a)-len(b)+1):
    broken=False
    for j in xrange(len(b)):
        if a[i+j]!=b[j] :
            broken = True
            break
    if not broken:
        count+=1

print count