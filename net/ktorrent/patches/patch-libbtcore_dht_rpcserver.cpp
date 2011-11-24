$NetBSD$

--- libbtcore/dht/rpcserver.cpp.orig	2011-11-24 02:12:17.000000000 +0000
+++ libbtcore/dht/rpcserver.cpp
@@ -22,6 +22,7 @@
 #include <QThread>
 #include <unistd.h>
 #include <string.h>
+#include <sys/select.h>
 #include <net/portlist.h>
 #include <util/log.h>
 #include <util/error.h>
