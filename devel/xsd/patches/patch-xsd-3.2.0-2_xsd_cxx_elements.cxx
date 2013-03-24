$NetBSD$

--- xsd-3.2.0-2/xsd/cxx/elements.cxx.orig	2013-03-23 19:59:02.000000000 +0000
+++ xsd-3.2.0-2/xsd/cxx/elements.cxx
@@ -208,7 +208,7 @@ namespace CXX
         }
         catch (SemanticGraph::InvalidPath const&)
         {
-          pair = path.native_file_string ();
+          pair = path.string ();
         }
       }
 
