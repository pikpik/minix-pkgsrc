$NetBSD$

--- ErrorLog.cc.orig	2008-12-16 11:20:56.000000000 +0000
+++ ErrorLog.cc
@@ -25,6 +25,7 @@
 ----------------------------------------------------------------------------*/
 
 #include "ErrorLog.h"
+#include <cstdio>
 
 const std::vector<std::string>::size_type CErrorLog::m_cMaxSize=100;
 	
