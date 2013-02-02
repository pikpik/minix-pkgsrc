$NetBSD$

--- core/digikam/album/albummanager.h.orig	2012-11-16 17:03:39.000000000 +0000
+++ core/digikam/album/albummanager.h
@@ -831,7 +831,7 @@ public:
     {
         foreach(T* t, list)
         {
-            append(AlbumPointer<T>(t));
+            this->append(AlbumPointer<T>(t));
         }
         return *this;
     }
