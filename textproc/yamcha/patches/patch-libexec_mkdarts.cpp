$NetBSD$

* require <cstdlib> header for atoi(3).

--- libexec/mkdarts.cpp.orig	2004-03-12 17:12:13.000000000 +0000
+++ libexec/mkdarts.cpp
@@ -23,6 +23,7 @@
 
 #include <cstdio>
 #include <cstring>
+#include <cstdlib>
 #include <iostream>
 #include <fstream>
 #include <string>
