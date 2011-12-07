$NetBSD$

--- klee/lib/Solver/Solver.cpp.orig	Thu Nov 24 15:07:25 2011
+++ klee/lib/Solver/Solver.cpp
@@ -29,6 +29,7 @@
 #include <vector>
 
 #include <errno.h>
+#include <unistd.h>
 #include <signal.h>
 #include <sys/wait.h>
 #include <sys/ipc.h>
