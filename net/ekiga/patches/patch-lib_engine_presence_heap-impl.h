$NetBSD$

--- lib/engine/presence/heap-impl.h.orig	2013-03-28 17:40:57.000000000 +0000
+++ lib/engine/presence/heap-impl.h
@@ -160,7 +160,7 @@ Ekiga::HeapImpl<PresentityType>::add_pre
 {
   presentity->questions.add_handler (questions.make_slot ());
 
-  add_object (presentity);
+  this->add_object (presentity);
 }
 
 template<typename PresentityType>
