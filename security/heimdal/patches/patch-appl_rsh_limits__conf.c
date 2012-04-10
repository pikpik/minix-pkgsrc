$NetBSD$

--- appl/rsh/limits_conf.c.orig	Tue Jan 10 21:53:51 2012
+++ appl/rsh/limits_conf.c
@@ -205,8 +205,10 @@ read_limits_conf(const char *file, const struct passwd
 	if(l->has_limit) {
 	    if(l->limit.rlim_cur > l->limit.rlim_max)
 		l->limit.rlim_cur = l->limit.rlim_max;
+#ifndef __minix
 	    if(setrlimit(l->resource, &l->limit) != 0)
 		syslog(LOG_ERR, "setrlimit RLIM_%s failed: %m", l->name);
+#endif
 	}
 	l->has_limit = 0;
     }
