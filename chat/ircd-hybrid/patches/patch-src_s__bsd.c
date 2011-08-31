$NetBSD$

--- src/s_bsd.c.orig	Wed Feb 28 04:17:46 2007
+++ src/s_bsd.c
@@ -24,8 +24,10 @@
 
 #include "stdinc.h"
 #ifndef _WIN32
+#ifndef __minix
 #include <netinet/in_systm.h>
 #include <netinet/ip.h>
+#endif
 #include <netinet/tcp.h>
 #endif
 #include "fdlist.h"
