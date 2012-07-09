$NetBSD$

--- include/ptlib/array.h.orig	2012-07-06 18:14:53.000000000 +0000
+++ include/ptlib/array.h
@@ -523,7 +523,7 @@ template <class T> class PScalarArray : 
       T t;
       stream >> t;
       if (!stream.fail())
-        SetAt(index, t);
+        this->SetAt(index, t);
     }
 };
 
