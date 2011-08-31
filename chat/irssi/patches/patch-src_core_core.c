$NetBSD$

--- src/core/core.c.orig	Sat Apr  3 16:19:38 2010
+++ src/core/core.c
@@ -113,6 +113,7 @@ static void read_settings(void)
 	}
 
 #ifdef HAVE_SYS_RESOURCE_H
+#ifndef __minix
 	if (!settings_get_bool("override_coredump_limit"))
 		setrlimit(RLIMIT_CORE, &orig_core_rlimit);
 	else {
@@ -123,6 +124,7 @@ static void read_settings(void)
 		if (setrlimit(RLIMIT_CORE, &rlimit) == -1)
                         settings_set_bool("override_coredump_limit", FALSE);
 	}
+#endif
 #endif
 #endif
 }
