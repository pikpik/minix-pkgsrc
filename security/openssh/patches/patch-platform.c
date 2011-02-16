$NetBSD$

Fix for Interix.

--- platform.c.orig	2011-01-11 06:02:25.000000000 +0000
+++ platform.c
@@ -81,7 +81,9 @@ platform_privileged_uidswap(void)
 	/* uid 0 is not special on Cygwin so always try */
 	return 1;
 #else
+#if !defined(HAVE_INTERIX)
 	return (getuid() == 0 || geteuid() == 0);
+#endif /* !HAVE_INTERIX */
 #endif
 }
 
