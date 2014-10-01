#!/bin/sh
echo "recursively removing .svn folders from"
pwd
rm -rf `find . -type d -name .svn`

mv -r `find ./* -type d -name *.htm*` ./
