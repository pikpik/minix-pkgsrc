$NetBSD$

--- src/bin/geomview/x11/gvmain.c.orig	2013-03-01 21:43:19.000000000 +0000
+++ src/bin/geomview/x11/gvmain.c
@@ -67,9 +67,7 @@ static    void  env_usage();
 
 /*****************************************************************************/
 	
-int main(argc, argv)
-unsigned int argc;
-char **argv;
+int main(int argc, char **argv)
 {
   int i;
   CameraStruct  cs;
