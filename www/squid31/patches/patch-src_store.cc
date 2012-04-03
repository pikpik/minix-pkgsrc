$NetBSD$

Fix compiling with Clang.

--- src/store.cc.orig	2012-01-08 10:01:40.000000000 +0000
+++ src/store.cc
@@ -374,7 +374,7 @@ StoreEntry::deferProducer(const AsyncCal
         deferredProducer = producer;
     else
         debugs(20, 5, HERE << "Deferred producer call is allready set to: " <<
-               *deferredProducer << ", requested call: " << *producer);
+               *deferredProducer);
 }
 
 void
