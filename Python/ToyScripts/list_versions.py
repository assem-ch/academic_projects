import xmlrpclib
import pprint
client = xmlrpclib.ServerProxy('http://pypi.python.org/pypi')
print client.package_releases('Whoosh',True)
