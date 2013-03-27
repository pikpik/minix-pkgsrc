$NetBSD$

--- src/cimom/server/OW_PlatformSignal.cpp.orig	2013-03-25 15:29:11.000000000 +0000
+++ src/cimom/server/OW_PlatformSignal.cpp
@@ -36,6 +36,7 @@
 #include "OW_PlatformSignal.hpp"
 #include "OW_UserUtils.hpp"
 #include <ostream>
+#include <cstring>
 
 namespace OW_NAMESPACE
 {
