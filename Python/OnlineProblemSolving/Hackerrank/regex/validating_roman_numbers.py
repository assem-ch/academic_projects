import re
X = raw_input()
roman = re.compile("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$")
print "True" if roman.match(X) else "False"