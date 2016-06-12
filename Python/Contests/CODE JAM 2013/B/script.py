#!/bin/python


##
def try_cut(a,N,M):
    ##
    values = reduce(lambda x,y: x|y, [set([a[i][j] for j in xrange(M)]) for i in  xrange(N)])
    max_grass=max(values)
    yard = [ [max_grass]*M ]*N
    FAILED=False
    for h in reversed(sorted(values - {max_grass})):
        #try_horizontal
        for i in xrange(N):
            if max(a[i])<=h:
                #cut
                for j in xrange(M):
                    yard[i][j]=h
        #try_vertical
        for j in xrange(M):
            if max([a[i][j] for i in xrange(N)])<=h:
                #cut
                for i in xrange(N):
                    yard[i][j]=h
        #test_success
        for i in xrange(N):
            for j in xrange(M):
                if a[i][j]==h and yard[i][j]!=h:
                    FAILED=True
                    break
            if FAILED:
                break
        if FAILED:
            break
            
    return "NO" if FAILED else "YES"

#prepare input
"""
f=open("in2","w")
import random

rand=random.randint
f.write("100\n")
for k in xrange(100):
    f.write("100 100\n")
    for i in xrange(100):
        s=[]
        for j in xrange(100):
            s.append(str(rand(1,100)))
        f.write(" ".join(s))
        f.write("\n")
"""



# read the input
f=open("in")
T=int(f.readline())


output=""
for i in xrange(T):
    raw_list=map(lambda x:int(x),f.readline()[:-1].split())
    N,M=raw_list[0],raw_list[1]
    print i
    a = []
    for j in xrange(N):
        a.append(map(lambda x:int(x),f.readline()[:-1].split()))
    output+="Case #%d: %s\n" % (i+1,try_cut(a,N,M))
    
    
    
    
OUTPUT=open("out","w")
OUTPUT.write(output)
print output
print "done"



    
    
    
