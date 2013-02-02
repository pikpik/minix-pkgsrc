$NetBSD$

--- initrov.c.orig	2013-01-11 01:31:12.000000000 +0000
+++ initrov.c
@@ -67,7 +67,7 @@ FILE *fp;
 //----------------------------------------------------------------------
 //  This is the Main routine for initrov 
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    int ShowStatus=FALSE,filenum;
    char msg[300];
