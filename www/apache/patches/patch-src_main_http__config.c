$NetBSD$

--- src/main/http_config.c.orig	Wed Aug 17 11:06:48 2011
+++ src/main/http_config.c
@@ -1437,7 +1437,7 @@ CORE_EXPORT(const char *) ap_init_virtual_host(pool *p
 {
     server_rec *s = (server_rec *) ap_pcalloc(p, sizeof(server_rec));
 
-#ifdef RLIMIT_NOFILE
+#if defined(RLIMIT_NOFILE) && !defined(__minix)
     struct rlimit limits;
 
     getrlimit(RLIMIT_NOFILE, &limits);
