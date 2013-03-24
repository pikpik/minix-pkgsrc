$NetBSD$

--- xpcom/ds/nsInterfaceHashtable.h.orig	2003-12-29 13:22:49.000000000 +0000
+++ xpcom/ds/nsInterfaceHashtable.h
@@ -111,7 +111,7 @@ nsInterfaceHashtable<KeyClass,Interface>
   (KeyType aKey, UserDataType* pInterface) const
 {
   typename nsBaseHashtable<KeyClass, nsCOMPtr<Interface>, Interface*>::EntryType* ent =
-    GetEntry(aKey);
+    this->GetEntry(aKey);
 
   if (ent)
   {
@@ -139,7 +139,7 @@ nsInterfaceHashtable<KeyClass,Interface>
   (KeyType aKey, PRBool* aFound) const
 {
   typename nsBaseHashtable<KeyClass, nsCOMPtr<Interface>, Interface*>::EntryType* ent =
-    GetEntry(aKey);
+    this->GetEntry(aKey);
 
   if (ent)
   {
