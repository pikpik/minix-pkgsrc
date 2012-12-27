$NetBSD$

- declare own functions

--- src/meta/plot.h~	2003-11-15 16:51:42.000000000 +0000
+++ src/meta/plot.h
@@ -50,6 +50,8 @@ extern void contpage(void);
 extern void printspan(void);
 extern void endpage(void);
 
+	/* xmeta.c */
+void replay(int, int, int, int);
 
 #ifdef __cplusplus
 }
