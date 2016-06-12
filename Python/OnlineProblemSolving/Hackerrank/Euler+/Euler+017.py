predefined = {
1: "One",
2: "Two",
3: "Three",
4: "Four",
5: "Five",
6: "Six",
7: "Seven",
8: "Eight",
9: "Nine",
10: "Ten",
11:  "Eleven",
12: "Twelve",
13:  "Thirteen",
14:  "Fourteen",
15:  "Fifteen",
16: "Sixteen",
17:  "Seventeen",
18: "Eighteen",
19:  "Nineteen",
20: "Twenty",
30:  "Thirty",
40:  "Forty",
50:  "Fifty",
60: "Sixty",
70:  "Seventy",
80:  "Eighty",
90:  "Ninety",
}

def inwords(x):
    if x in predefined:
        return predefined[x]
    if x >= 1000000000:
        a = x/1000000000
        b = x%1000000000
        return inwords(a) + " " + "Billion" + " " +  inwords(b)
    if x >= 1000000:
        a = x/1000000
        b = x%1000000
        return inwords(a) + " " + "Million" + " " +  inwords(b)
    if x >= 1000:
        a = x/1000
        b = x%1000
        return inwords(a) + " " + "Thousand" + " " +  inwords(b)
    if x >= 100:
        a = x/100
        b = x%100
        return inwords(a) + " " + "Hundred"+ " " + inwords(b)
    if x>20:
        a = x/10
        b = x%10
        return predefined[a*10] + " " + predefined [b]

for i in xrange(input()):
    N = input()
    print inwords(N)