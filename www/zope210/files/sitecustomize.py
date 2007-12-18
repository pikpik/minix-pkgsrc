#
# $NetBSD$
#
# set default character encoding 
#

import os, sys

env = os.environ

try :
  	encoding = env['ZOPE210_DEFAULT_ENCODING']
	sys.setdefaultencoding(encoding)
except:
	pass
