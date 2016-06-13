#!/bin/python


import itertools


# read the input
f=open("in")
T=int(f.readline())


output=""
for i in xrange(T):
    success=False
    raw_list=map(lambda x:int(x),f.readline()[:-1].split())
    N,a=raw_list[0],raw_list[1:]
    deja_vu={}
    for x in itertools.product([0,1],repeat=N):
	b=itertools.compress(a,x)
	somme=sum(b)	
	#print somme #,b
	if deja_vu.has_key(somme):
		print "deja vu"
		bt=itertools.compress(a,deja_vu[somme].pop())
		print b,"=",bt,"=",somme
		success=True
		break;
	else:
	    deja_vu[somme]=[x]
	
    if success:
          output+="Case #%d:\n%s\n%s\n" % (i+1," ".join(map(lambda x:str(x),b))," ".join(map(lambda x:str(x),bt)))
    else:
	  output+="Case #%d:\nImpossible\n"
    print output
    
    
    
    
    
OUTPUT=open("out","w")
OUTPUT.write(output)
print output
print "done"
    
    
    