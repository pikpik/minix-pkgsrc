$NetBSD$

--- misc/uuidd.c.orig	Thu Aug 13 01:39:57 2009
+++ misc/uuidd.c
@@ -81,8 +81,13 @@ static void create_daemon(void)
 	if (chdir("/")) {}	/* Silence warn_unused_result warning */
 	(void) setsid();
 	euid = geteuid();
+#ifdef __minix
+       if (setuid(euid) < 0)
+               die("setuid");
+#else
 	if (setreuid(euid, euid) < 0)
 		die("setreuid");
+#endif
 }
 
 static ssize_t read_all(int fd, char *buf, size_t count)
@@ -509,16 +514,26 @@ int main(int argc, char **argv)
 		if (setresgid(gid, gid, gid) < 0)
 			die("setresgid");
 #else
+#ifdef __minix
+               if (setgid(gid) < 0)
+                       die("setgid");
+#else
 		if (setregid(gid, gid) < 0)
 			die("setregid");
 #endif
+#endif
 
 #ifdef HAVE_SETRESUID
 		if (setresuid(uid, uid, uid) < 0)
 			die("setresuid");
 #else
+#ifdef __minix
+		if (setuid(uid) < 0)
+			die("setreuid");
+#else
 		if (setreuid(uid, uid) < 0)
 			die("setreuid");
+#endif
 #endif
 	}
 	if (num && do_type) {
