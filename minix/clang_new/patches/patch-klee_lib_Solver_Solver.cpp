$NetBSD$

--- klee/lib/Solver/Solver.cpp.orig	Thu Aug 11 01:14:45 2011
+++ klee/lib/Solver/Solver.cpp
@@ -29,6 +29,7 @@
 #include <vector>
 
 #include <errno.h>
+#include <unistd.h>
 #include <signal.h>
 #include <sys/wait.h>
 #include <sys/ipc.h>
