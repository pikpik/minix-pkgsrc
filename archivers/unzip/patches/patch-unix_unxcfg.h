$NetBSD$

--- unix/unxcfg.h.orig	Thu Apr 16 18:36:12 2009
+++ unix/unxcfg.h
@@ -111,7 +111,9 @@ typedef struct stat z_stat;
 
 #ifdef BSD
 #  include <sys/time.h>
-#  include <sys/timeb.h>
+#  ifndef __minix
+#    include <sys/timeb.h>
+#  endif
 #  if (defined(_AIX) || defined(__GLIBC__) || defined(__GNU__))
 #    include <time.h>
 #  endif
