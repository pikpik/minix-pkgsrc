$NetBSD$

--- src/lex.c.orig	2012-10-26 13:05:36.000000000 +0000
+++ src/lex.c
@@ -730,7 +730,7 @@ static scanDirflags ()
 /******************************************************************************
                                                                    DIRLINE   */
 
-static scanDirline ()
+static void scanDirline (void)
 {
   FILE *file;
   lineno += antnewline;
