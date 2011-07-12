$NetBSD$

--- gettext-tools/gnulib-lib/spawni.c.orig	Tue Mar  1 16:39:29 2011
+++ gettext-tools/gnulib-lib//spawni.c
@@ -223,10 +223,12 @@ __spawni (pid_t *pid, const char *file,
     }
 #endif
 
+#ifndef __minix
   /* Set the process group ID.  */
   if ((flags & POSIX_SPAWN_SETPGROUP) != 0
       && setpgid (0, attrp->_pgrp) != 0)
     _exit (SPAWN_ERROR);
+#endif
 
   /* Set the effective user and group IDs.  */
   if ((flags & POSIX_SPAWN_RESETIDS) != 0
