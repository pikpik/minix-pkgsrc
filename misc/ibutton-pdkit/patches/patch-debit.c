$NetBSD$

--- debit.c.orig	2013-01-11 01:31:04.000000000 +0000
+++ debit.c
@@ -69,7 +69,7 @@ FILE *fp;
 //----------------------------------------------------------------------
 //  This is the Main routine for debit
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    int ShowStatus=FALSE,filenum,LOOP,i,cnt,exit_code=EXIT_SUCCESS;
    char msg[200];
