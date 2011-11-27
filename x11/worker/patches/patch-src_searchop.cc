$NetBSD$

--- src/searchop.cc.orig	2011-11-27 01:22:52.000000000 +0000
+++ src/searchop.cc
@@ -29,6 +29,7 @@
 #include "fileviewer.hh"
 #include "flagreplacer.hh"
 #include <aguix/acontainerbb.h>
+#include <typeinfo>
 
 const char *SearchOp::name = "SearchOp";
 std::list<SearchOp::ResultStore*> SearchOp::_stored_results;
