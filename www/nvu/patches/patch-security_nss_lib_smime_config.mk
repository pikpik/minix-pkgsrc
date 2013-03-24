$NetBSD$

--- security/nss/lib/smime/config.mk.orig	2013-03-24 14:47:55.000000000 +0000
+++ security/nss/lib/smime/config.mk
@@ -92,3 +92,4 @@ ifeq ($(OS_TARGET),SunOS)
 MKSHLIB += -R '$$ORIGIN'
 endif
 
+MKSHLIB += -Wl,-rpath,${PREFIX}/lib/nvu-1.0
