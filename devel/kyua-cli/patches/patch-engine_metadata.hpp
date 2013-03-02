$NetBSD$

--- engine/metadata.hpp.orig	2013-02-28 21:58:41.000000000 +0000
+++ engine/metadata.hpp
@@ -44,7 +44,7 @@
 
 namespace utils {
 namespace config { class tree; }
-namespace datetime { class delta; }
+namespace datetime { struct delta; }
 namespace fs { class path; }
 namespace units { class bytes; }
 }  // namespace utils
