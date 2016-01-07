L = 2000000
min_diff=L

for x in range(2, 101):
    for y in range(x, 101):
       diff = abs(x*(x + 1) * y*(y + 1) / 4 - L)
       if diff < min_diff:
           area, min_diff = x * y, diff

print  area