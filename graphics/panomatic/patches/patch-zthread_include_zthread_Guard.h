$NetBSD$

--- zthread/include/zthread/Guard.h.orig	2012-11-15 14:59:53.000000000 +0000
+++ zthread/include/zthread/Guard.h
@@ -108,7 +108,7 @@ class CompoundScope {
   }
 
   template <class LockType>
-  static void createScope(LockHolder<LockType>& l, unsigned long ms) {
+  static bool createScope(LockHolder<LockType>& l, unsigned long ms) {
 
     if(Scope1::createScope(l, ms))
       if(!Scope2::createScope(l, ms)) {
@@ -428,7 +428,7 @@ public:
   template <class U, class V>
   Guard(Guard<U, V>& g) : LockHolder<LockType>(g) {
 
-    LockingPolicy::shareScope(*this, extract(g));
+    LockingPolicy::shareScope(*this, this->extract(g));
     
   }
 
