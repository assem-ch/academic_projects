N = input()

fib = 0
fib1=0
fib2=1
l=[]
for i in xrange(N):
    l.append(fib)
    fib = fib1+fib2
    fib2, fib1=fib1,fib

print map(lambda x: x**3, l)