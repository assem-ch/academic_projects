#!/bin/python



from threading import Thread
from Queue import PriorityQueue

def resolve (i,A,B,p):
      minimal=99999999999999999
      ##
      true_percent= reduce(lambda a,b: a*b,p)
      stratigy_if_keep_typing=(B-A+1)*true_percent+(2*B)*(1-true_percent) 
      minimal=stratigy_if_keep_typing if minimal>stratigy_if_keep_typing else minimal
      ##
      stratigy_if_press_enter=B+2
      minimal=stratigy_if_press_enter if minimal>stratigy_if_press_enter else minimal
      ## 
      for bs in xrange(1,(A/2)+1):
	  stratigy_if_j_backspace=(B-A+1+2*bs)*true_percent
	  p_last=1
	  for j in xrange(0,A):
	      
	      jfalse_percent= p_last*(1-p[j])
	      p_last*=p[j]
	      if j<A-bs:
		  stratigy_if_j_backspace+=(2*B-A+2+2*bs)*jfalse_percent
	      else:
		  stratigy_if_j_backspace+=(B-A+1+2*bs)*jfalse_percent
	  
	  minimal=stratigy_if_j_backspace if minimal>stratigy_if_j_backspace else minimal
	  
       
      queue.put("Case #%d: %f\n" %(i+1,minimal))





# read the input
f=open("in")
T=int(f.readline())

queue=PriorityQueue()

mythreads=[]
for i in xrange(T):
    A,B=tuple(map(int,f.readline().split()))
    print i,A,B
    p=map(float,f.readline().split())
    thread = Thread(target=resolve, args=(i,A,B,p))
    thread.start()
    mythreads.append(thread)

    
    
    
for v in xrange(T):
    print queue.get()
    



output=""
OUTPUT=open("out","w")
OUTPUT.write(output)
print output
print "done"
    