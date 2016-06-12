string = raw_input()

found = True
from collections import Counter

c = Counter(string)
first=True
for e in c.most_common():
    if e[1]%2:
        if not first:
            found = False
            break
        first = False


if not found:
    print("NO")
else:
    print("YES")