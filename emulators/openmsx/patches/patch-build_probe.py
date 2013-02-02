$NetBSD$

DragonFly is a BSD whose platform name does not end in "BSD"
Just look for it specifically.

--- build/probe.py.orig	2012-08-12 12:29:37.000000000 +0000
+++ build/probe.py
@@ -396,7 +396,7 @@ def main(compileCommandStr, outDir, plat
 						break
 				else:
 					distroRoot = '/usr/local'
-			elif platform.endswith('bsd'):
+			elif platform == 'dragonfly' or platform.endswith('bsd'):
 				distroRoot = environ.get('LOCALBASE', '/usr/local')
 				print 'Using libraries from ports directory %s.' % distroRoot
 			elif platform == 'pandora':
