import re

s = raw_input()
r = re.compile("^(\d\d):(\d\d):(\d\d)(\w\w)$")

_, h,m,s,f, _ = r.split(s)

if f == "PM" and h != "12":
    h = str(int(h)+12)

elif f == "AM" and h == "12":
    h = "00"

print "%s:%s:%s" % (h,m,s)