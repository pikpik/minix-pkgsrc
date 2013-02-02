--- dbus/dbus-sysdeps-util-unix.c.orig	Fri Sep 28 19:17:25 2012
+++ dbus/dbus-sysdeps-util-unix.c	Fri Feb  1 23:28:42 2013
@@ -798,6 +798,7 @@
     struct group g_str;
     dbus_bool_t b;
 
+#ifdef _SC_GETGR_R_SIZE_MAX
     /* retrieve maximum needed size for buf */
     buflen = sysconf (_SC_GETGR_R_SIZE_MAX);
 
@@ -805,8 +806,12 @@
      * so just recast here.
      * https://bugs.freedesktop.org/show_bug.cgi?id=17061
      */
+#else
+	buflen = -1;
+#endif
     if ((long) buflen <= 0)
       buflen = 1024;
+
 
     result = -1;
     while (1)
