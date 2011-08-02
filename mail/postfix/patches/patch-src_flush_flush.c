$NetBSD$

--- src/flush/flush.c.orig	Fri Apr 17 20:03:59 2009
+++ src/flush/flush.c
@@ -577,10 +577,12 @@ static int flush_send_path(const char *path, int how)
     if (count > 0 && ftruncate(vstream_fileno(log), (off_t) 0) < 0)
 	msg_fatal("%s: truncate fast flush logfile %s: %m", myname, path);
 
+#ifndef NO_UTIMES
     /*
      * Workaround for noatime mounts. Use futimes() if available.
      */
     (void) utimes(VSTREAM_PATH(log), (struct timeval *) 0);
+#endif
 
     /*
      * Request delivery and clean up.
