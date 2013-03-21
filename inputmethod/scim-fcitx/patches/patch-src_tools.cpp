$NetBSD$

* require unistd.h for access(2).

--- src/tools.cpp.orig	2005-05-20 14:41:12.000000000 +0000
+++ src/tools.cpp
@@ -12,6 +12,7 @@ using namespace scim;
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/stat.h>
+#include <unistd.h>
 #include <limits.h>
 #include <string.h>
 
