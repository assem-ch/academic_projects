'''
Created on 18 janv. 2010

@author: assem
'''
import re
import twill


number_re = re.compile("[0-9]")
value_re = re.compile("value\=[\"][^\"]+[\"]")
string_re = re.compile("[^\"]+")

def primary(num):
    p = True
    for x in range(2, num):
        if num % x == 0:
            p = False
            break
    return p


      


def resolve(string):
    res = string
    numbers = [int(num) for num in number_re.findall(res)]
    res = number_re.sub("", res)
    res = "".join([chr(ord(ch) + 1) for ch in res[:25]])
    sommeC = 0
    sommeP = 0
    for num in numbers:
        if num != 0 and num != 1:
            if primary(num):sommeP += num
            else:sommeC += num
    produit = sommeC * sommeP
    res += str(produit)
    return res


bw = twill.get_browser()


bw.go("http://www.hackthissite.org/user/login")
print bw.get_title()
form = bw.get_all_forms() [0]
username = raw_input("username:")
form.set_value(username, "username")
password = raw_input("password:")
form.set_value(password, "password")
bw.submit()
print bw.get_title()
bw.go("http://www.hackthissite.org/missions/prog/12/")

value = bw.get_html()
string = string_re.findall(value_re.findall(value)[0])[1]  
print string

res = resolve(string)
print res
#print bw.get_html()

form = bw.get_all_forms() [1]
form.set_value(res, name="solution")
twill.commands.fv("2", "solution", res)

twill.commands.browser.submit()


print bw.get_title()
print bw.get_html()
