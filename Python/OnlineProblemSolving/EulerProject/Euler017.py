
predefined = {
1: "one",
2: "two",
3: "three",
4: "four",
5: "five",
6: "six",
7: "seven",
8: "eight",
9: "nine",
10: "ten",
11:  "eleven",
12: "twelve",
13:  "thirteen",
14:  "fourteen",
15:  "fifteen",
16: "sixteen",
17:  "seventeen",
18: "eighteen",
19:  "nineteen",
20: "twenty",
30:  "thirty",
40:  "forty",
50:  "fifty",
60: "sixty",
70:  "seventy",
80:  "eighty",
90:  "ninety",
1000: "one thousand"
}

def inwords(x):
    if x in predefined:
	return predefined[x]
    if x >= 100:
	a = x/100
	b = x%100
	number = predefined[a] + " " + "hundred"
	if b:
	    number += " and " + inwords(b)
	return number
    if x>20:
	a = x/10
	b = x%10
        return predefined[a*10] + "-" + predefined [b]



	

for x in xrange(1,1001):
    print inwords(x)

print sum([len(inwords(x).replace(" ","").replace("-","")) for x in xrange(1,1001)])