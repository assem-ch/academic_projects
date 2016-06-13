

days_till_month= {
1: 0,
2: 31,
3: 59,
4: 90,
5: 120,
6: 151,
7: 181,
8: 212,
9: 243,
10: 273,
11: 304,
12: 334

}

days = lambda  dd, mm, yy: ( yy - 1900 ) * 365 + (yy - 1900)/4 + days_till_month[mm] + (1 if mm > 2 and yy % 4 == 0 else 0 )+ dd -1


date1 = days(1, 1, 1901)
date2 = days(31, 12, 2000)

weeks1= date1/7
weeks2= date2/7

new_week1 = date1%7
new_week2 = date2%7

print date1, weeks1, new_week1
print date2, weeks2, new_week2

print (weeks2-weeks1 -1) / 171