import time
st = time.time()


N,a,b,n,d = 1000000 , 3,7, 2,5

p =(N-d)/b

print p*a+n, p*b+d
end = time.time()

print "{:.20f}".format((end -st)*1000)