import re
import os

#regex
las_ext=re.compile(".+\.las")
block=re.compile("\~[A-Z \t]+")
comment=re.compile("#[A-Za-z \t\.]+")
base=re.compile("[A-Za-z0-9\. ]+[:\t]*")
word=re.compile("([A-Za-z0-9\.]+[ ]?)+")


all_info={}


for file0 in os.listdir("."):
	if re.match(las_ext,file0) :
		#another file
		all_info[file0]={}
		las=open(file0,"r")
		for line0 in las.readlines():
			if re.match(block,line0):
				#begin of block
				extracted=line0[1:-2].replace("\t","")
				all_info[file0][extracted]=[]
				tmp=all_info[file0][extracted]
			elif re.match(comment,line0):
				tmp.append(tuple(re.findall(word,line0)))
			else :
				tmp.append(tuple(re.findall(word,line0)))	
		 
		 
		 
		 
for fileZ in all_info.values():
	for blockZ in fileZ.values():
		for lineZ in blockZ:
			print lineZ
			
		
