$NetBSD$

--- libxsd-frontend-1.15.0/xsd-frontend/semantic-graph/elements.cxx.orig	2013-03-23 19:39:54.000000000 +0000
+++ libxsd-frontend-1.15.0/xsd-frontend/semantic-graph/elements.cxx
@@ -324,6 +324,6 @@ namespace XSDFrontend
 std::wostream&
 operator<< (std::wostream& os, XSDFrontend::SemanticGraph::Path const& path)
 {
-  return os << path.native_file_string ().c_str ();
+  return os << path.c_str ();
 }
 
