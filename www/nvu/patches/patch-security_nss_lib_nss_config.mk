$NetBSD$

--- security/nss/lib/nss/config.mk.orig	2013-03-24 14:32:56.000000000 +0000
+++ security/nss/lib/nss/config.mk
@@ -116,6 +116,7 @@ MKSHLIB += -R '$$ORIGIN'
 endif
 endif
 
+MKSHLIB += -Wl,-rpath,${PREFIX}/lib/nvu-1.0
 
 ifeq (,$(filter-out WINNT WIN95,$(OS_TARGET)))
 ifndef NS_USE_GCC
