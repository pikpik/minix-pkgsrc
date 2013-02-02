$NetBSD: patch-src-linux.c,v 1.1 2012/02/20 15:45:19 reinoud Exp $

--- src/linux.c.orig	2012-04-16 15:37:00.000000000 +0000
+++ src/linux.c
@@ -63,6 +63,8 @@ int main(int argc, char *argv[])
         get_executable_name(exedir, 511);
         p = get_filename(exedir);
         p[0] = 0;
+        /* data was referred relative to the executable; fix: */
+        strcpy(exedir, "@BEMDATADIR@");
         config_load();
 //        printf("Main\n");
         main_init(argc, argv);
