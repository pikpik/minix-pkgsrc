$NetBSD$

--- murgil/makeport.c.orig	1995-02-24 22:19:42.000000000 +0100
+++ murgil/makeport.c	2012-01-20 14:59:37.892111852 +0100
@@ -9,6 +9,7 @@
 #include <signal.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/file.h>
 #include <netinet/in.h>
 #include <netdb.h>
 #include "select.h"
