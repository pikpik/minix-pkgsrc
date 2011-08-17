$NetBSD$

--- src/main/util_script.c.orig	Wed Jul 12 08:16:05 2006
+++ src/main/util_script.c
@@ -702,6 +702,7 @@ API_EXPORT(int) ap_call_exec(request_rec *r, child_inf
     r->server->error_log = stderr;
 #endif
 
+#ifndef __minix
 #ifdef RLIMIT_CPU
     if (conf->limit_cpu != NULL) {
         if ((setrlimit(RLIMIT_CPU, conf->limit_cpu)) != 0) {
@@ -742,6 +743,7 @@ API_EXPORT(int) ap_call_exec(request_rec *r, child_inf
 			 "usage limit");
 	}
     }
+#endif
 #endif
 
 #ifdef OS2
