$NetBSD$

Do not run a shell command when it is "None".

--- numpy/distutils/fcompiler/gnu.py.orig	2011-03-11 05:56:15.000000000 +0000
+++ numpy/distutils/fcompiler/gnu.py
@@ -268,7 +268,7 @@ class Gnu95FCompiler(GnuFCompiler):
 
     def _universal_flags(self, cmd):
         """Return a list of -arch flags for every supported architecture."""
-        if not sys.platform == 'darwin':
+        if not sys.platform == 'darwin' or cmd == None:
             return []
         arch_flags = []
         # get arches the C compiler gets.
