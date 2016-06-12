

number = "".join(map(str,xrange(100)))

number = ""
cpt = 0
while(len(number)<=1000001):
    number += str(cpt)
    cpt+=1
    
    
print number[:20], number[11]

print int(number[1])* int(number[10])* int(number[100])* int(number[1000])* int(number[10000])* int(number[100000])* int(number[1000000])