#! usr/bin/python
#coding: utf-8



import re
import sys
import os, os.path

bk_ext=["pdf","doc","ps","odt","docx","chm"]
ext_regx=re.compile("\..+")

def args():
    lien_de_base=None
    if len(sys.argv)<=1 :
	lien_de_base="/"
    elif "--help" in sys.argv:
	print "used : python ",sys.argv[0], """[lien de base] [--help] \n
   for example:\n\t python """,sys.argv[0]," / \n\t python ",sys.argv[0]," ./ \n\t python ",sys.argv[0]," ../assem/ "
	sys.exit()
    else :
	lien_de_base=sys.argv[1]
    return lien_de_base

def build_ext_regx(bk_ext):
	regx=".+\.(("+bk_ext[0]+")"
	for x in bk_ext[1:]:
		regx+="|("+x+")"
	regx+=")$"
	return regx


def rec_browse(is_book,lien="/",list_books=[]):
      	
	if os.access(lien,os.R_OK) and os.access(lien,os.F_OK):
		try: 
			list_dir=os.listdir(lien)
		except :
			list_dir=None
			pass
			
		for x in list_dir:
			abslien=lien+x
			if os.path.islink(abslien):
				pass
			elif os.path.isdir(abslien):
				rec_browse(is_book,abslien+os.path.sep,list_books)
				#print "browsing",abslien
			elif os.path.isfile(abslien):
				if re.match(is_book,x):
					print len(list_books)+1,":",x
					extention=ext_regx.findall(x)[0][1:]
					list_books.append({"ext":extention,"name":x.replace("."+extention,""),"path":abslien})					
		
	return list_books


if __name__ == "__main__" :
	cpt=0
	lien_de_base=args()
	regx=build_ext_regx(bk_ext)
	is_book=re.compile(regx)
	results=rec_browse(is_book,lien_de_base)
	for record in results:
		cpt+=1		
		print "Record %d :" % cpt
		for key in record:
			print "\t",key.upper(),"=",record[key],";"
