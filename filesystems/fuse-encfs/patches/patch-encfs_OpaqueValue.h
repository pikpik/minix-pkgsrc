$NetBSD$

--- encfs/OpaqueValue.h.orig	2013-02-25 17:46:44.000000000 +0000
+++ encfs/OpaqueValue.h
@@ -19,6 +19,8 @@
 #ifndef _OpaqueValue_incl_
 #define _OpaqueValue_incl_
 
+#include <typeinfo>
+
 namespace rel
 {
     class OpaqueValue;
