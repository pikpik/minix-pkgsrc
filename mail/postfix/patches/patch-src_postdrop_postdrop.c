$NetBSD$

--- src/postdrop/postdrop.c.orig	Sat Jan 16 01:21:50 2010
+++ src/postdrop/postdrop.c
@@ -339,7 +339,9 @@ int     main(int argc, char **argv)
      * allowed to invoke postdrop_sig().
      */
     signal(SIGPIPE, SIG_IGN);
+#ifdef SIGXFSZ
     signal(SIGXFSZ, SIG_IGN);
+#endif
 
     signal(SIGINT, postdrop_sig);
     signal(SIGQUIT, postdrop_sig);
