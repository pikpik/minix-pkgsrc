$NetBSD$

Fix build with python25

--- zim/plugins/linesorter.py.orig	2011-04-07 20:21:33.000000000 +0000
+++ zim/plugins/linesorter.py
@@ -3,6 +3,8 @@
 # Copyright 2011 NorfCran <norfcran@gmail.com>
 # License:  same as zim (gpl)
 
+from __future__ import with_statement
+
 import gtk
 
 from zim.plugins import PluginClass
