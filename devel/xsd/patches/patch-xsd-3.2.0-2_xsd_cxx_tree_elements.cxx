$NetBSD$

--- xsd-3.2.0-2/xsd/cxx/tree/elements.cxx.orig	2013-03-28 16:25:23.000000000 +0000
+++ xsd-3.2.0-2/xsd/cxx/tree/elements.cxx
@@ -1282,7 +1282,7 @@ namespace CXX
       }
       catch (SemanticGraph::InvalidPath const&)
       {
-        path_str = path.native_file_string ();
+        path_str = path.string ();
       }
 
       String inc_path;
