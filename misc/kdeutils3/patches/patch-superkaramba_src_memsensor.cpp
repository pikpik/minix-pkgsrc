$NetBSD$

--- superkaramba/src/memsensor.cpp.orig	2013-01-14 21:47:52.000000000 +0000
+++ superkaramba/src/memsensor.cpp
@@ -30,6 +30,7 @@
 #include <sys/sysctl.h>
 #include <sys/sched.h>
 #include <sys/swap.h>
+#include <uvm/uvm_extern.h>
 #endif
 
 #include <kprocio.h>
