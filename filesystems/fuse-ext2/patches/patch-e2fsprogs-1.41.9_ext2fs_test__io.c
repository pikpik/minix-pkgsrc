$NetBSD$

--- e2fsprogs-1.41.9/ext2fs/test_io.c.orig	2012-12-20 13:30:54.000000000 +0000
+++ e2fsprogs-1.41.9/ext2fs/test_io.c
@@ -8,6 +8,7 @@
  * License.
  * %End-Header%
  */
+#include "config.h"
 
 #include <stdio.h>
 #include <string.h>
