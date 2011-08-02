$NetBSD$

--- src/util/vstream_tweak.c.orig	Thu Jul 17 15:03:07 2008
+++ src/util/vstream_tweak.c
@@ -89,6 +89,7 @@ int     vstream_tweak_tcp(VSTREAM *fp)
     SOCKOPT_SIZE mss_len = sizeof(mss);
     int     err;
 
+#if defined(TCP_MAXSEG)
     /*
      * Avoid Nagle delays when VSTREAM buffers are smaller than the MSS.
      * 
@@ -106,6 +107,10 @@ int     vstream_tweak_tcp(VSTREAM *fp)
     }
     if (msg_verbose)
 	msg_info("%s: TCP_MAXSEG %d", myname, mss);
+#else
+    if (msg_verbose)
+	msg_info("%s: TCP_MAXSEG not set, not found defined");
+#endif
 
     /*
      * Fix for recent Postfix versions: increase the VSTREAM buffer size if
