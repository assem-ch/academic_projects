#!/bin/python




# read the input
f=open("in")
T=int(f.readline())

output=""
for i in xrange(T):
    N,=tuple(map(int,f.readline().split()))
    print T,N
    Star1=Star2=[]
    for j in xrange(N):
	a,b=tuple(map(int,f.readline().split()))
	Star1.append(a)
	Star2.append(b)
	
    Stars=range(N)
    Total=0;
    passed=0
 
    change1=change2=True
    while((change1 or change2 ) and Stars):
      print change1, change2
      change1=change2=False

      for x in xrange(len(Star2)):
	    if x in Stars and  Total >= Star2[x]:
		Total+=2;
		change2=True
		passed+=1
		Stars.remove(x)
		print "2",N,Total
      if not change2:

		for y in xrange(len(Star1)):
		      if y in Stars and Total >= Star1[y]:
			  Total+=1;
			  change1=True
			  passed+=1
			  
			  print "1",N,Total
	  

	    
	    
	
    
    output+="Case #%d: %f\n" %(i+1,passed)
    
    
    
    
    
OUTPUT=open("out","w")
OUTPUT.write(output)
print output
print "done"
    