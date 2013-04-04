$NetBSD$

--- ntpd.h.orig	Sun May 14 05:29:21 2006
+++ ntpd.h
@@ -22,8 +22,12 @@
 #include "openbsd-compat/sys-queue.h"
 #include <sys/time.h>
 #include <netinet/in.h>
+#ifdef HAVE_NETINET_IN_SYSTM_H
 #include <netinet/in_systm.h>
+#endif
+#ifdef HAVE_NETINET_IP_H
 #include <netinet/ip.h>
+#endif
 #include <arpa/inet.h>
 #include <netdb.h>
 #include <stdarg.h>
