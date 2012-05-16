$NetBSD$

--- uwsgi.h.orig	2011-09-11 05:50:42.000000000 +0000
+++ uwsgi.h
@@ -210,6 +210,10 @@ extern int pivot_root(const char *new_ro
 #include <sys/devpoll.h>
 #elif defined(__HAIKU__)
 #else
+#ifdef __DragonFly__
+/* avoid clash with sys/user.h inclusion in logging.c */
+#define _KERNEL_STRUCTURES 
+#endif /* __DragonFly__ */
 #include <sys/event.h>
 #endif
 
