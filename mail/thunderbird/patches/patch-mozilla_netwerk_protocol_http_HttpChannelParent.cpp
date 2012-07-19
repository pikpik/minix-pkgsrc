$NetBSD$

--- mozilla/netwerk/protocol/http/HttpChannelParent.cpp.orig	2012-07-12 15:25:25.000000000 +0000
+++ mozilla/netwerk/protocol/http/HttpChannelParent.cpp
@@ -340,6 +340,13 @@ HttpChannelParent::RecvUpdateAssociatedC
 // Compiling this with GCC <= 4.4 fails with an internal compiler error
 #pragma GCC optimize ("O0")
 #endif
+// Compiling with a version of GCC <= 4.4 fails with an internal compiler
+// error.
+#if !defined(__GNUC__) || \
+  (__GNUC__ >= 5) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 5)
+#pragma GCC optimize ("O0")
+#endif
+
 
 bool
 HttpChannelParent::RecvRedirect2Verify(const nsresult& result, 
