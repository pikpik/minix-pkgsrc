$NetBSD$

--- ksysguard/ksysguardd/NetBSD/ProcessList.c.orig	2013-01-16 23:02:11.000000000 +0000
+++ ksysguard/ksysguardd/NetBSD/ProcessList.c
@@ -35,6 +35,7 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/user.h>
+#include <sys/resource.h>
 #include <unistd.h>
 #include <signal.h>
 
