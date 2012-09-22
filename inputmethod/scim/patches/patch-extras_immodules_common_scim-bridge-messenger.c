$NetBSD$

* alloca.h is required for alloca(3C) on Solaris.

--- extras/immodules/common/scim-bridge-messenger.c.orig	2012-06-13 15:22:28.000000000 +0000
+++ extras/immodules/common/scim-bridge-messenger.c
@@ -25,6 +25,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#ifdef __sun
+#include <alloca.h>
+#endif
 
 #include <sys/select.h>
 #include <sys/socket.h>
