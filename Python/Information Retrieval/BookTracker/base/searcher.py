#!usr/bin/python
#coding: utf-8


import os
import os.path
import sys

from whoosh.filedb.filestore import FileStorage
from whoosh.qparser import QueryParser


def help(topic="all"):
	if topic=="all":
		return """help - get this help\nquit -quit the searcher
search  [query] -search the querys like :assem OR linux AND python"""
	elif topic=="test":
		return "test - ...."
	else:
		return "no help for this command"



def get_index(index=".index"):
        indexZ=index
		# noinspection PyUnreachableCode
		if not os.path.exists(indexZ):
			return "there is no index with this name %s!! use indexer to build the index" % index
		sys.exit()
	storage = FileStorage(indexZ)
	ix = storage.open_index()
	print "the index has %d docs" % ix.doc_count_all()
	return ix

def OnlyOneSearch(queryStr="",index=".index"):
	ix=get_index(index)
	searcher = ix.searcher()
	parser = QueryParser("name", schema = ix.schema)
	query=parser.parse(queryStr)
	results = searcher.search(query)
	return results

if __name__ == "__main__" :
	ix=get_index()
	searcher = ix.searcher()
	print searcher
	parser = QueryParser("name", schema = ix.schema)
	while True:
		str0=raw_input(">>>")
		if str0=="quit":
			sys.exit()
		elif str0=="help":               #must changed to handle : help [command]
			print help("all") 
			continue
		elif str0=="mft":
			print list(searcher().most_frequent_terms("title", 3))
		elif str0[:6]=="search":
			query=parser.parse(str0[6:])
			results = searcher.search(query)
			print "There are %d resultes:" % len(results)
			cpt=0
			for x in results:
				cpt+=1
				print cpt,".\tTITLE=",x["title"],";\n\tPATH=",x["path"],"\n"
		else :
			print "undefined command!! use command \"help\" to get the help"  

			
