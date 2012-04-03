$NetBSD$

Do not enforce version restriction; let pkgsrc framework deal with it.

--- pdf-parser.py.orig	2010-01-09 23:56:08.000000000 +0000
+++ pdf-parser.py
@@ -894,5 +894,5 @@ def TestPythonVersion(enforceMaximumVers
             print 'Should you encounter problems, please use Python version %d.%d.%d' % __maximum_python_version__
 
 if __name__ == '__main__':
-    TestPythonVersion(enforceMaximumVersion=True)
+    TestPythonVersion(enforceMaximumVersion=False)
     Main()
