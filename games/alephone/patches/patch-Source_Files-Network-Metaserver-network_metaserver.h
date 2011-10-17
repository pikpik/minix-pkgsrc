$NetBSD: patch-Source_Files-Network-Metaserver-network_metaserver.h.diff,v 1.1 2011/09/25 19:47:38 joerg Exp $

--- Source_Files/Network/Metaserver/network_metaserver.h.orig	2011-09-24 20:39:50.000000000 +0000
+++ Source_Files/Network/Metaserver/network_metaserver.h
@@ -32,6 +32,7 @@
 #include <map>
 #include <memory> // auto_ptr
 #include <set>
+#include <stdexcept>
 
 #include "Logging.h"
 
