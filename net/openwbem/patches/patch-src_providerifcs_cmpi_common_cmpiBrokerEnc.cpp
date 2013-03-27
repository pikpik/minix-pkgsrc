$NetBSD$

--- src/providerifcs/cmpi/common/cmpiBrokerEnc.cpp.orig	2013-03-25 15:27:10.000000000 +0000
+++ src/providerifcs/cmpi/common/cmpiBrokerEnc.cpp
@@ -19,6 +19,7 @@
  *
  */
 
+#include <cstring>
 #include "cmpisrv.h"
 #include "OW_CIMException.hpp"
 #include "OW_CIMProperty.hpp"
