$NetBSD$

--- dbus/dbus-sysdeps-util-unix.c.orig	Wed May  6 17:26:48 2009
+++ dbus/dbus-sysdeps-util-unix.c
@@ -871,6 +871,7 @@ fill_group_info (DBusGroupInfo    *info,
     struct group g_str;
     dbus_bool_t b;
 
+#ifdef _SC_GETGR_R_SIZE_MAX
     /* retrieve maximum needed size for buf */
     buflen = sysconf (_SC_GETGR_R_SIZE_MAX);
 
@@ -878,8 +879,12 @@ fill_group_info (DBusGroupInfo    *info,
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
@@ -1233,4 +1238,4 @@ fail:
   _dbus_string_free (&cmdline);
   _dbus_string_free (&path);
   return FALSE;
-}
\ No newline at end of file
+}
