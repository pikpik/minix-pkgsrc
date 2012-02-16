$NetBSD$

--- murgil/contoport.c.orig	1995-02-24 22:19:40.000000000 +0100
+++ murgil/contoport.c	2012-01-20 15:01:20.773471557 +0100
@@ -6,6 +6,7 @@
 #include <sys/types.h>
 #include <fcntl.h>
 #include <sys/socket.h>
+#include <sys/file.h>
 #include <netinet/in.h>
 #include <netdb.h>
 #include "select.h"
