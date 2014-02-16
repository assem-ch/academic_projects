#!/bin/python

## used functions
length=lambda x:len(str(x))
recycle=lambda x,length: x/10 + x%10 * 10**(length-1)


### reading input
INPUT=open("in")
T=int(INPUT.readline())
output=""
for i in xrange(T):
    case_param=INPUT.readline().split()
    A=int(case_param[0]); B=int(case_param[1])
    cpt=0
    print "A=%d,B=%d" %(A,B)
    for n in xrange(A,B+1):
	  temp=n
	  leng=length(A)
	  tuples=set()
	  for k in xrange(leng):
	      m=recycle(temp,leng)
	      temp=m
	      if m>n and m<=B and m not in tuples:
		  #print (n,m)
		  cpt+=1
  
	      tuples.add(m)
	      
    ###
    output+="Case #%d: %d\n" % (i+1,cpt)
	  
	  
OUTPUT=open("out","w")
OUTPUT.write(output)
print output
print "done"
    
    
    


