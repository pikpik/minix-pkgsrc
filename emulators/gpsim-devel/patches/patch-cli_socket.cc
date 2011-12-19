$NetBSD$

--- cli/socket.cc.orig	2005-08-31 14:46:35.000000000 +0000
+++ cli/socket.cc
@@ -27,6 +27,7 @@ Boston, MA 02111-1307, USA.  */
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 #include <sys/types.h>
