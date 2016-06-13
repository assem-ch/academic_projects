'''
Created on 18 janv. 2010

@author: assem
'''
import bz2, sys


uncompressedData = bz2.BZ2File("corrupted.png.bz2")

print uncompressedData.readlines()
