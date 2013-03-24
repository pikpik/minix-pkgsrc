$NetBSD$

--- security/nss/lib/ssl/config.mk.orig	2013-03-24 14:50:44.000000000 +0000
+++ security/nss/lib/ssl/config.mk
@@ -84,4 +84,6 @@ ifeq ($(OS_TARGET),SunOS)
 MKSHLIB += -R '$$ORIGIN'
 endif
 
+MKSHLIB += -Wl,-rpath,${PREFIX}/lib/nvu-1.0
+
 endif
