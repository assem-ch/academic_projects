'''
Created on 18 janv. 2010

@author: assem
'''
import re
import twill


number_re = re.compile("[-]?[0-9]+")
shift_re = re.compile("Shift\:[ ][-]?[0-9]+")
gen_re = re.compile("Generated[ ]String\:[ ](?:[0-9]+[^0-9])+")


def resolve(string, shift):
    list = number_re.findall(string)
    res = ""
    for item in list:
        res += chr(int(item) - shift)
    return res


    

bw = twill.get_browser()
#bw.go("http://www.hackthissite.org")
bw.go("http://www.hackthissite.org/user/login")
print bw.get_title()
form = bw.get_all_forms() [0]
username = raw_input("username:")
form.set_value(username, "username")
password = raw_input("password:")
form.set_value(password, "password")
bw.submit()
print bw.get_title()
bw.go("http://www.hackthissite.org/missions/prog/11/")
text = bw.get_html()
string = ",".join(number_re.findall(gen_re.findall(text)[0]))
print string
shift = int(number_re.findall(shift_re.findall(text)[0])[0])
print shift    

res = resolve(string, shift)
print res
print text
form = bw.get_all_forms() [0]
form.set_value(res, "solution")
bw.submit()

print bw.get_title()
print bw.get_html()
