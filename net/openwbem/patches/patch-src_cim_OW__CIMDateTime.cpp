$NetBSD$

--- src/cim/OW_CIMDateTime.cpp.orig	2011-11-24 02:50:22.000000000 +0000
+++ src/cim/OW_CIMDateTime.cpp
@@ -44,6 +44,8 @@
 #include "OW_Assertion.hpp"
 
 #include <cstdio>
+#include <cstdlib>
+#include <cstring>
 #if defined(OW_HAVE_ISTREAM) && defined(OW_HAVE_OSTREAM)
 #include <istream>
 #include <ostream>
