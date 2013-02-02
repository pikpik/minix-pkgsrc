$NetBSD$

--- kmail/kmsystemtray.cpp.orig	2012-04-27 16:31:37.000000000 +0000
+++ kmail/kmsystemtray.cpp
@@ -464,10 +464,10 @@ void KMSystemTray::updateNewMessageNotif
 
 void KMSystemTray::updateNewMessages()
 {
-  for ( QMap<QGuardedPtr<KMFolder>, bool>::Iterator it = mPendingUpdates.begin();
-        it != mPendingUpdates.end(); ++it)
+  for ( QMap<QGuardedPtr<KMFolder>, bool>::Iterator it2 = mPendingUpdates.begin();
+        it2 != mPendingUpdates.end(); ++it2)
   {
-  KMFolder *fldr = it.key();
+  KMFolder *fldr = it2.key();
   if ( !fldr ) // deleted folder
     continue;
 
