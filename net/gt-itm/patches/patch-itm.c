$NetBSD$

--- itm.c.orig	2012-12-25 18:50:14.000000000 +0000
+++ itm.c
@@ -304,7 +304,7 @@ main(int argc, char **argv)
 
     if (argc == 1) {
 	printf("itm <spec-file0> <spec-file1> ....\n\n");
-	return;
+	return 1;
     }
     while (--argc) {
 
