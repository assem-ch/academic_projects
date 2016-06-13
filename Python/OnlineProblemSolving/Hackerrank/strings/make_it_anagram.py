a = sorted(raw_input())
b = sorted(raw_input())

temp_a = list(a)
temp_b = list(b)
for element in a:
    if element in temp_b:
        temp_a.remove(element)
        temp_b.remove(element)
        
print len(temp_a)+len(temp_b)