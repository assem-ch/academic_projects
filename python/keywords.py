import requests

url = "http://stats.alwaysdata.com/index.php?module=API&method=Referrers.getKeywords&format=JSON&idSite=15781&period=range&date=2014-04-04,2014-04-10&expanded=1&token_auth=35a822ee83a302bc3dd81e6772e7dba8&filter_limit=50"
payload = { }

r = requests.post(url,payload)


for e in eval(r.content):
    print str(e['nb_visits'])+ "! " 
    print e["label"].decode('utf-8')
