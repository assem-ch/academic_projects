#!/bin/python


for d in xrange(10):
	for e in xrange(10):
		if e==d: continue
		y=(d+e)%10
		y1=(d+e)//10
		if y==d or y==e: continue
		for n in xrange(10):
			if n==d or n==e or n==y: continue
			for r in xrange(10):
				if r==n or r==d or r==e or r==y: continue
				if e!=(n+r+y1)%10: continue
				e1=(n+r+y1)//10
				for o in xrange(10):
					if o==n or o==r or o==d or o==e or o==y: continue
					if n!=(e+o+e1)%10: continue
					n1=(e+o+e1)//10
					for s in xrange(10):
						if s==o or s==n or s==r or s==d or s==e or s==y: continue
						for m in xrange(1,10):
							if m==s or m==o or m==n or m==r or m==d or m==e or m==y: continue
							if o!=(s+m+n1)%10:continue
							o1=(s+m+n1)//10
							if m!=o1:continue
							print s,e,n,d,"+",m,o,r,e,"=",m,o,n,e,y
							
							
					
					
