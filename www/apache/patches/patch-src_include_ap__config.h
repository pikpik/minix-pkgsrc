$NetBSD$

--- src/include/ap_config.h.orig	Wed Jul 12 08:16:05 2006
+++ src/include/ap_config.h
@@ -73,6 +73,13 @@ stat() properly */
 
 #include "os.h"
 
+
+#if defined(__minix)
+#define HAVE_FCNTL_SERIALIZED_ACCEPT
+#define USE_FCNTL_SERIALIZED_ACCEPT
+#warning mnix
+#endif
+
 /* Define one of these according to your system. */
 #if defined(MINT)
 typedef int rlim_t;
@@ -700,8 +707,8 @@ extern char *crypt();
 #undef NO_SETSID
 #define HAVE_SYSLOG 1
 
-#elif defined(__FreeBSD__) || defined(__bsdi__)
-#if defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__bsdi__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <osreldate.h>
 #endif
 #define HAVE_GMTOFF 1
@@ -1305,7 +1312,7 @@ extern int ap_execve(const char *filename, char * cons
  * so we don't have to.  Sigh...
  */
 
-#if defined(CRAY) || (defined(__arm) && !defined(LINUX))
+#if defined(CRAY) || (defined(__arm) && !(defined(LINUX) || defined(NETBSD)))
 #ifdef __STDC__
 #define XtOffset(p_type,field) _Offsetof(p_type,field)
 #else
