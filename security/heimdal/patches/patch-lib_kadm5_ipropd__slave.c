$NetBSD$

--- lib/kadm5/ipropd_slave.c.orig	Tue Jan 10 21:53:51 2012
+++ lib/kadm5/ipropd_slave.c
@@ -735,8 +735,10 @@ main(int argc, char **argv)
 
     if (0);
 #ifndef NO_SIGXCPU
+#ifdef SIGXCPU
     else if(exit_flag == SIGXCPU)
 	krb5_warnx(context, "%s CPU time limit exceeded", getprogname());
+#endif
 #endif
     else if(exit_flag == SIGINT || exit_flag == SIGTERM)
 	krb5_warnx(context, "%s terminated", getprogname());
