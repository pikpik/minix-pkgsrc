$NetBSD$

--- globe.c.orig	2012-04-17 16:08:21.000000000 +0000
+++ globe.c
@@ -731,8 +731,8 @@ static char* globes[NGLOBES][NLINES] =
     };
 
 
-void
-main( int argc, char* argv )
+int
+main(void)
     {
     time_t now;
     int gnum, lnum;
