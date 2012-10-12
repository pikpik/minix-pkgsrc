$NetBSD$

Required for gcc 4.7 at least (taken from upstream)

--- lib/krb5/krb/x-deltat.y.orig	2012-08-08 22:27:56.000000000 +0000
+++ lib/krb5/krb/x-deltat.y
@@ -44,6 +44,7 @@
 #ifdef __GNUC__
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wuninitialized"
+#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
 #endif
 
 #include <ctype.h>
