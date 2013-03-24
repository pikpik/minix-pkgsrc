$NetBSD$

--- xpcom/ds/nsRefPtrHashtable.h.orig	2004-01-31 12:37:36.000000000 +0000
+++ xpcom/ds/nsRefPtrHashtable.h
@@ -140,7 +140,7 @@ nsRefPtrHashtable<KeyClass,RefPtr>::GetW
   (KeyType aKey, PRBool* aFound) const
 {
   typename nsBaseHashtable<KeyClass, nsRefPtr<RefPtr>, RefPtr*>::EntryType* ent =
-    GetEntry(aKey);
+    this->GetEntry(aKey);
 
   if (ent)
   {
