$NetBSD$

--- libkcal/listbase.h.orig	2012-04-27 15:32:46.000000000 +0000
+++ libkcal/listbase.h
@@ -67,7 +67,7 @@ class ListBase : public QValueList<T *>
 
     bool removeRef( T *t )
     {
-      QValueListIterator<T *> it = find( t );
+      QValueListIterator<T *> it = this->find( t );
       if ( it == QValueList<T*>::end() ) {
         return false;
       } else {
