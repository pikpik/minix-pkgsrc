$NetBSD$

--- klee/tools/klee/main.cpp.orig	Thu Aug 11 01:14:44 2011
+++ klee/tools/klee/main.cpp
@@ -47,6 +47,7 @@
 #include <fstream>
 #include <cerrno>
 #include <dirent.h>
+#include <unistd.h>
 #include <errno.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
