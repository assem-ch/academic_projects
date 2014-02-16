#!/bin/python

import math
## used functions
LENGTH=lambda p1,p2: sqrt((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)

PLANE
NB
def dawaran(p,center,angle):
    l=LENGTH(p,center):
	
    return (center[0]+l*math.cos(angle),center[1]+l*math.sin(angle))
    

def ping(p1,p2,D):
    angle=math.atan((y2-y1)/(x2-x1))
    new_p1=(p1[0]+0.5*math.cos(angle),p1[0]+0.5*math.sin(angle)),
    if new_p1[0]%1==0.0 and new_p1[1]%1==0.0:
	if PLANE(new_p1[0],new_p1[1])=="X":
	   NB+=1;
	if PLANE(new_p1[0],new_p1[1])==".":
	   ping(new_p1,p2,D-0.5)
    if new_p1[0]%1==0.5 and new_p1[1]%1==0.5:
	   adja=sum([PLANE(new_p1[0]+0.5,new_p1[1]+0.5)=="#",PLANE(new_p1[0]-0.5,new_p1[1]+0.5)=="#",PLANE(new_p1[0]+0.5,new_p1[1]-0.5)=="#",PLANE(new_p1[0]-0.5,new_p1[1]-0.5)=="#")
	   if adja==3:
	      new_p2=dawaran(p2,p1,math.pi)
	      ping(new_p1,new_p2,D-0.5)
	      
    if new_p1[0]%0.5!=0.0 or new_p1[1]%0.5!=0.5:
	    new_p2=dawaran(p2,p1,math.pi)
	   
    
  
    
def locate_player(plane):
    for i in xrange(len(plane)):
      for j in xrange(len(plane[i])):
	  if plane[i][j]=="X":
	      return (i,j)
def locate_mirrors(plane):
    for i in xrange(len(plane)):
      for j in xrange(len(plane[i])):
	  if plane[i][j]=="#":
	      yield (i,j)
  
	      
	      
### read input
INPUT=open("d.in")
nbcase=int(INPUT.readline())

for c in xrange(nbcase):
   raw_case_param=INPUT.readline().split()
   H=int(raw_case_param[0])
   W=int(raw_case_param[1])
   D=int(raw_case_param[2])
   
   plane=[INPUT.readline()[:-1]  for i in xrange(H)] 

   
   
   player=locate_player(plane)
   mirrors=locate_mirrors(plane)
  
   ##  ping every mirrors
   for m in mirrors:
	ping(player, m, D)
   