$NetBSD: patch-include_libiberty.h,v 1.1 2012/06/23 22:13:02 marino Exp $

--- include/libiberty.h.orig	Wed Sep 28 19:04:30 2011
+++ include/libiberty.h
@@ -106,7 +106,17 @@ extern int countargv (char**);
    to find the declaration so provide a fully prototyped one.  If it
    is 1, we found it so don't provide any declaration at all.  */
 #if !HAVE_DECL_BASENAME
-#if defined (__GNU_LIBRARY__ ) || defined (__linux__) || defined (__FreeBSD__) || defined (__OpenBSD__) || defined(__NetBSD__) || defined (__CYGWIN__) || defined (__CYGWIN32__) || defined (__MINGW32__) || defined (HAVE_DECL_BASENAME)
+#if defined (__GNU_LIBRARY__ ) \
+ || defined (__linux__) \
+ || defined (__minix) \
+ || defined (__DragonFly__) \
+ || defined (__FreeBSD__) \
+ || defined (__OpenBSD__) \
+ || defined (__NetBSD__) \
+ || defined (__CYGWIN__) \
+ || defined (__CYGWIN32__) \
+ || defined (__MINGW32__) \
+ || defined (HAVE_DECL_BASENAME)
 extern char *basename (const char *);
 #else
 /* Do not allow basename to be used if there is no prototype seen.  We
