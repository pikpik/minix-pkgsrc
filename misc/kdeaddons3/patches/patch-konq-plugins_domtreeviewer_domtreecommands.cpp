$NetBSD$

--- konq-plugins/domtreeviewer/domtreecommands.cpp.orig	2012-11-09 11:39:21.000000000 +0000
+++ konq-plugins/domtreeviewer/domtreecommands.cpp
@@ -79,13 +79,15 @@ ManipulationCommandSignalEmitter* Manipu
 
 // == ChangedNodeSet ================================================
 
-namespace domtreeviewer {
-
+namespace DOM {
 // collection of nodes for which to emit the nodeChanged signal
 inline static bool operator <(const DOM::Node &n1, const DOM::Node &n2)
 {
   return (long)n1.handle() - (long)n2.handle() < 0;
 }
+}
+
+namespace domtreeviewer {
 
 class ChangedNodeSet : public QMap<DOM::Node, bool>
 {
