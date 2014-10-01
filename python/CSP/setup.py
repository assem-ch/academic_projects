#!python
#coding=utf-8

import glob


from setuptools import setup,find_packages



setup(
	name="myCSP",
	version=0.1,
	package_dir={'myCSP':'.'},
	packages=['myCSP'],
	author="Assem Chelli",
	author_email="assem.ch@gmail.com",
	description="CSP algorithm implementation",
    long_description=""" ... """,
	license="GPL",
	keywords="CSP AI resolve nqueen ",
	url="",
	download_url="",
	#install_requires=['xxxxxxx >= 0.3.18'],

	include_package_data=True,

    data_files=[ ('examples',glob.glob('./*'))],
   
    
	zip_safe=True,

	
	classifiers=[
	"Development Status :: 3 - Alpha",
	"Intended Audience :: Developers",
	"License :: OSI Approved :: GNU General Public License (GPL)",
	"Natural Language :: English",
	"Operating System :: OS Independent",
	"Programming Language :: Python :: 2.6",
	"Topic :: Software Development :: Libraries :: Python Modules",
	],
	
)
