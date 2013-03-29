$NetBSD$

--- lib/engine/presence/cluster-impl.h.orig	2013-03-28 17:41:32.000000000 +0000
+++ lib/engine/presence/cluster-impl.h
@@ -147,7 +147,7 @@ Ekiga::ClusterImpl<HeapType>::add_heap (
 
   add_connection (heap, heap->questions.add_handler (questions.make_slot ()));
 
-  add_object (heap);
+  this->add_object (heap);
 }
 
 template<typename HeapType>
