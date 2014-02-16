#!/bin/python



### used functions
def possible_triples(X,p):
    sp=np=False
    #print "\n",X,"=",
    X1=X/3
    x1_proba=filter(lambda x: x  in xrange(11),[X1,X1+1,X1-1])
    for x1 in x1_proba:
	X2=(X-X1)/2
	x2_proba=filter(lambda x:  x  in xrange(11)  and abs(x-x1)<=2,[X2,X2+1,X2-1])
	if sp and np:
	      break;
	for x2 in x2_proba:
	    X3=X-x1-x2
	    x3=X3
	    if  x3  in xrange(11) and abs(x3-x1)<=2 and abs(x3-x2)<=2 and max(x1,x2,x3)>=p:
		  #print (x1,x2,x3),
		  if is_surprised((x1,x2,x3)):
		      sp=True
		  else:
		      np=True
		  if sp and np:
		      break;
		      
		      
    return (sp,np)
		      
		  
is_surprised=lambda t: abs(t[1]-t[0])==2 or abs(t[2]-t[0])==2 or abs(t[2]-t[1])==2
best_result=lambda t:max(t)


## reading input
INPUT=open("b.in")
nb_cases=int(INPUT.readline())

output=""
for c in xrange(nb_cases):
    raw_case_param=INPUT.readline().split()
    N=int(raw_case_param[0])
    S=int(raw_case_param[1])
    p=int(raw_case_param[2])
    t_list=map(int,raw_case_param[3:])
    
    print c
    scenarios=[(0,0)]
    for i in xrange(N):
      t=t_list[i]
      sp,np=possible_triples(t,p)
      new_scenarios=[]
      for scen in scenarios:
	  if np:
	      new_scenarios.insert(0,(scen[0],scen[1]+1))
	  elif sp and scen[0]<S:
	      new_scenarios.insert(0,(scen[0]+1,scen[1]+1))
	      new_scenarios.insert(0,scen)
	  else:
	      new_scenarios.insert(0,scen)
	      
      scenarios=list(new_scenarios)

    MAX= max(map(lambda x:x[1],scenarios)+[0])
    output+="Case #%d: %d\n" % (c+1,MAX)
    
OUTPUT=open("bb.out","w")
OUTPUT.write(output)
print output
print "done"
    
	      
	  
	  
    
    



