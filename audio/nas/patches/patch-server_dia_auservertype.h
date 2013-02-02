$NetBSD$

--- server/dia/auservertype.h.orig	Thu Feb 26 01:16:01 2009
+++ server/dia/auservertype.h
@@ -14,7 +14,7 @@
 # define SGI_SERVER
 #endif /* sgi */
 
-#if defined(__DragonFly__) || defined(__FreeBSD_kernel__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(linux) || (defined(SVR4) && (defined(SYSV386) || defined(i386))) || defined(__CYGWIN__)
+#if defined(__DragonFly__) || defined(__FreeBSD_kernel__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(linux) || (defined(SVR4) && (defined(SYSV386) || defined(i386))) || defined(__CYGWIN__) || defined(__OpenBSD__)
 # define VOXWARE_SERVER
 #endif /* voxware */
 
