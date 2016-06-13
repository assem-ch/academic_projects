# encoding: utf-8
# author: bigOTHER


ANSWER_OFFERS = False # Change it it True, in order to send offers

username = u"تجربتي"
password = u"qwerty0"


## How to use:
# in Linux, run: 
# $ sudo crontab -e
# than add this line 
# 0/1 * * * * python /home/user/yasser_hunter.py
# dont forget to add permissions
# $ chmod +x /home/user/yasser_hunter.py

import re
import cookielib
import urllib2
import urllib
from BeautifulSoup import BeautifulSoup
import feedparser
	

rss = u"http://www.djelfa.info/vb/external.php?type=RSS2&forumids=331"
forum = u"http://www.djelfa.info/vb/forumdisplay.php?f=331"
login_url = 'http://www.djelfa.info/vb/login.php?do=login'
base_url = 'http://www.djelfa.info/vb/'
offer_proof = [u"للبيع", u"مقابل", u"فليكسي",u"CCP", u"ccp"]
offer_deny = [u"للتبادل"]
blacklist_keywords = [""]
blacklist_users = [u"woolf", u"doog"]
message_title = u"طلب"
message_body = u"احجز لي كل المبلغ" 
keywords = u"نتلر|neteller"
history_file = u"history_yasser.txt"



is_neteller = lambda y: re.search(keywords, y, re.IGNORECASE)
is_offer = lambda y: any(x in y for x in offer_proof) and all(x not in y for x in offer_deny)
get_id = lambda y: re.search("(\d+)",y).groups()[0]
is_closed = lambda y: "threadclosed.gif" in y



cj = cookielib.CookieJar()
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))


params = { 
 			'vb_login_username' : username.encode("windows-1256"), 
 			'vb_login_password': password,
 			's':"",
 			'securitytoken':"guest",
 			'do':"login",
 			'vb_login_md5password':"",
 			'vb_login_md5password_utf':""
 		}

login_data = urllib.urlencode(params)
login_result = opener.open(login_url, login_data)

soup = BeautifulSoup(login_result)
forwardlink = soup.findAll('form')[0].get('action')
opener.open(forwardlink)


try:
	f = open(history_file)
except:
	f = open(history_file, "w+")

deja_vu = f.readlines()

while(True):
d = feedparser.parse(rss)

opencpt = 0 
cpt=0
newcpt = 0
allcpt = len(d["entries"])

for e in d["entries"]:
	if get_id(e["id"])+"\n" in deja_vu:
		continue

	deja_vu.insert(0, get_id(e["id"])+"\n")
	newcpt += 1
	if  is_neteller(e["title"]) and is_offer(e["title"]) and  e["author"] not in blacklist_users :
		cpt+=1
		print e["author"],"\n", e["title"]
		print e["id"]
		#print e["description"]
		#print e["content"][0]["value"]
		#print e

		result = opener.open(e["id"])
		html = "".join(result.readlines())

		if is_closed(html):
			print "\033[91m**** CLOSED\033[0m"
			print
			continue

		opencpt+=1
		soup = BeautifulSoup(result)
		replylink = base_url + soup.find(src='images/buttons/reply.gif').parent.get('href')
		reply_result = opener.open(replylink)

		soup = BeautifulSoup(reply_result)
		postlink = base_url + soup.findAll('form')[1].get('action')

		params = { 
 			'message' : message_body.encode("windows-1256"), 
 			'title': message_title.encode("windows-1256"),
 			'iconid': '0',
 			'wysiwyg':'1',
 			's':"",
 			'securitytoken': soup.find("input" , {"name" : "securitytoken"})["value"],
 			'do':"postreply",
 			't': soup.find("input" , {"name" : "t"})["value"],
 			'p': soup.find("input" , {"name" : "p"})["value"],
 			'specifiedpost':'0',
 			'posthash':soup.find("input" , {"name" : "posthash"})["value"],
 			'poststarttime':soup.find("input" , {"name" : "poststarttime"})["value"],
 			'loggedinuser':soup.find("input" , {"name" : "loggedinuser"})["value"],
 			'multiquoteempty':"",
 			"emailupdate":"1",
 			"rating":"0",
 		}

 		post_params = urllib.urlencode(params)

 		if ANSWER_OFFERS:
 			result = opener.open(postlink, post_params)
 		
 		#html = "".join(result.readlines())
		#f = open("index.html", "w")	
		#f.write(html)	
		#f.close()
		print "\033[94m**** OFFER PROPOSED!\033[0m"
		print "------------------------------------"
		print 
	else:
		#print e["author"],"\n", e["title"] 
		#print e["id"]
		#print "\033[93m***** NOT A NETTELLER OFFER\033[0m"
		#print "------------------------------------"
		#print
		pass 
		

print "%d RSS entries, %d new ones, %d are neteller offers, \033[91m%d are closed\033[0m , \033[94m %d are open\033[0m" %  (allcpt, newcpt, cpt, cpt - opencpt, opencpt)

f.close()

f = open(history_file, "w")

f.write("".join(deja_vu[0:30]))




