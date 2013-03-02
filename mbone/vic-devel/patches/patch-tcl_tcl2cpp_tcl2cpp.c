$NetBSD$

--- tcl/tcl2cpp/tcl2cpp.c.orig	2013-03-01 14:55:53.000000000 +0000
+++ tcl/tcl2cpp/tcl2cpp.c
@@ -38,6 +38,7 @@ void put(int c)
 		printf("%u,%c", c, ((++n & 0xf) == 0) ? '\n' : ' ');
 }
 
+int
 main(int argc, char **argv)
 {
 	int c;
