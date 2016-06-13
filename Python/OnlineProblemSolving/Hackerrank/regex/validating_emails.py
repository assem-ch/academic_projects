import re

N = int(raw_input())

emails = []
reg = re.compile("^[a-zA-Z0-9-_]+@[a-zA-Z0-9]+\.[a-z]{1,3}$")#^[\w-_]+@[\w]+\..{1,3}$

for i in xrange(N):
    new_email = raw_input()
    if reg.match(new_email):
        emails.append(new_email)

print sorted(emails)