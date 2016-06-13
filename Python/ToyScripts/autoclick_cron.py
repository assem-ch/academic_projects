import requests

url = "http://www.star28.com/site/rating.php?id=17548&value=2"
payload = { 'action':'yes' }

r = requests.post(url,payload)

print r.content
