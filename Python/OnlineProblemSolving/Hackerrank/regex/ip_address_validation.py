import re

is_4 = re.compile("^(\d{1,3}\.){3}\d{1,3}$")
is_6 = re.compile("^([\da-fA-F]{1,4}\:){7}[\da-fA-F]{1,4}$")

for t in xrange(input()):
    ip = raw_input()

    if is_4.match(ip) and len(filter(lambda x: x < 256, map(int, ip.split(".")))) == 4:
                              print "IPv4"
    elif is_6.match(ip):
                              print "IPv6"
    else:
                              print "Neither"