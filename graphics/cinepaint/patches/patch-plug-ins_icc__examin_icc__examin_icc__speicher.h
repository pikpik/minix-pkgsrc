$NetBSD$

--- plug-ins/icc_examin/icc_examin/icc_speicher.h.orig	2011-11-23 17:06:00.000000000 +0000
+++ plug-ins/icc_examin/icc_examin/icc_speicher.h
@@ -32,6 +32,8 @@
 #define ICC_SPEICHER_H
 
 #include "icc_utils.h"
+#include <cstdlib>
+#include <cstring>
 #include <string>
 
 #define DBG_SPEICHER_START   if(icc_debug >= 3) DBG_PROG_START
