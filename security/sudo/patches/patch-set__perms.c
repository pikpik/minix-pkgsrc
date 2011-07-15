$NetBSD$

--- set_perms.c.orig	Fri Jul 15 23:23:16 2011
+++ set_perms.c
@@ -522,7 +522,7 @@ runas_setgroups()
 	aix_restoreauthdb();
 #  endif
     } else {
-	if (setgroups(ngroups, groups) < 0)
+	if (groups && setgroups(ngroups, groups) < 0)
 	    log_error(USE_ERRNO|MSG_ONLY, "can't set runas group vector");
 # endif /* HAVE_GETGROUPS */
     }
@@ -531,7 +531,7 @@ runas_setgroups()
 static void
 restore_groups()
 {
-    if (user_ngroups >= 0 && setgroups(user_ngroups, user_groups) < 0)
+    if (user_groups && user_ngroups >= 0 && setgroups(user_ngroups, user_groups) < 0)
 	log_error(USE_ERRNO|MSG_ONLY, "can't reset user group vector");
 }
 
