$NetBSD$

--- xpcom/glue/nsClassHashtable.h.orig	2012-11-17 15:47:45.000000000 +0000
+++ xpcom/glue/nsClassHashtable.h
@@ -98,7 +98,7 @@ PRBool
 nsClassHashtable<KeyClass,T>::Get(KeyType aKey, T** retVal) const
 {
   typename nsBaseHashtable<KeyClass,nsAutoPtr<T>,T*>::EntryType* ent =
-    GetEntry(aKey);
+    this->GetEntry(aKey);
 
   if (ent)
   {
