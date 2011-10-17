$NetBSD$

* include <string.h> for memcpy(3), and so on.

--- flip.c.orig	2001-04-25 15:48:59.000000000 +0000
+++ flip.c
@@ -7,6 +7,7 @@
 
 #include <stdlib.h>
 #include <stdio.h>
+#include <string.h>
 #include <sys/time.h>
 #include <unistd.h>
 #include <aalib.h>
