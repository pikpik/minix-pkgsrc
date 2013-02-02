$NetBSD$

--- c_source/idintime.c.orig	2012-07-03 12:50:24.000000000 +0000
+++ c_source/idintime.c
@@ -14,7 +14,7 @@ struct complex { real r,i; };
 
 void idint(struct complex*x,int,real*);
 
-idintime( x, length, wtab )
+void idintime( x, length, wtab )
 struct complex x[];
 int length;
 real *wtab;
