$NetBSD$

--- xpcom/ds/nsClassHashtable.h.orig	2003-06-19 18:42:23.000000000 +0000
+++ xpcom/ds/nsClassHashtable.h
@@ -98,7 +98,7 @@ PRBool
 nsClassHashtable<KeyClass,T>::Get(KeyType aKey, T** retVal) const
 {
   typename nsBaseHashtable<KeyClass,nsAutoPtr<T>,T*>::EntryType* ent =
-    GetEntry(aKey);
+    this->GetEntry(aKey);
 
   if (ent)
   {
