$NetBSD$

--- libxsd-frontend-1.15.0/xsd-frontend/semantic-graph/schema.hxx.orig	2013-03-23 19:41:18.000000000 +0000
+++ libxsd-frontend-1.15.0/xsd-frontend/semantic-graph/schema.hxx
@@ -234,7 +234,7 @@ namespace XSDFrontend
       friend class Bits::Graph<SemanticGraph::Node, Edge>;
 
       using Scope::add_edge_left;
-      using Node::add_edge_right;
+      using SemanticGraph::Node::add_edge_right;
 
       Void
       add_edge_left (Uses& e)
