$NetBSD$

--- kadmin/kadm_conn.c.orig	Tue Jan 10 21:53:51 2012
+++ kadmin/kadm_conn.c
@@ -189,8 +189,10 @@ wait_for_connection(krb5_context contextp,
 
     pgrp = getpid();
 
+#ifndef __minix
     if(setpgid(0, pgrp) < 0)
 	err(1, "setpgid");
+#endif
 
     signal(SIGTERM, terminate);
     signal(SIGINT, terminate);
