$NetBSD$

--- libkms/linux.c.orig	2010-03-06 00:21:13.000000000 +0100
+++ libkms/linux.c	2012-01-10 20:40:06.019270181 +0100
@@ -40,6 +40,11 @@
 
 #include <sys/stat.h>
 
+#ifdef __sun
+#include <sys/types.h>
+#include <sys/mkdev.h>
+#endif
+
 #include "internal.h"
 
 #define PATH_SIZE 512
