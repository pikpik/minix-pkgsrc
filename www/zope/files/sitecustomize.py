#
# $NetBSD$
#
# Set default character encoding for Zope.
#

import os, sys

env = os.environ

try :
  	encoding = env['ZOPE@ZOPE_VERSION@_DEFAULT_ENCODING']
	sys.setdefaultencoding(encoding)
except:
	pass
