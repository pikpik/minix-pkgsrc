--- ntp.c.orig	Sun May 14 05:29:23 2006
+++ ntp.c	Mon Apr  1 17:45:41 2013
--- ntp.c.orig	Sun May 14 05:29:23 2006
+++ ntp.c
@@ -113,8 +113,11 @@ ntp_main(int pipe_prnt[2], struct ntpd_conf *nconf)
 		fatal("stat");
 	if (stb.st_uid != 0 || (stb.st_mode & (S_IWGRP|S_IWOTH)) != 0)
 		fatal("bad privsep dir permissions");
+/* Don't chroot on Minix -- we won't be able to hit /dev/udp */
+#ifndef __minix
 	if (chroot(chrootdir) == -1)
 		fatal("chroot");
+#endif
 	if (chdir("/") == -1)
 		fatal("chdir(\"/\")");
 
@@ -130,10 +133,13 @@ ntp_main(int pipe_prnt[2], struct ntpd_conf *nconf)
 	conf = nconf;
 	setup_listeners(se, conf, &listener_cnt);
 
+/* XXX Minix dies here, comment out for now */
+#ifndef __minix
 	if (setgroups(1, &pw->pw_gid) ||
 	    setresgid(pw->pw_gid, pw->pw_gid, pw->pw_gid) ||
 	    setresuid(pw->pw_uid, pw->pw_uid, pw->pw_uid))
 		fatal("can't drop privileges");
+#endif
 
 	endservent();
 
