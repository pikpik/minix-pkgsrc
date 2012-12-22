$NetBSD: patch-src_Utilities_Set.cpp,v 1.1 2011/11/24 14:00:53 joerg Exp $

--- src/Utilities/Set.cpp.orig	2008-03-17 18:56:18.000000000 +0000
+++ src/Utilities/Set.cpp
@@ -39,7 +39,7 @@ QValueList<T> Utilities::Set<T>::toList(
 }
 
 template <class T>
-Utilities::Set<T>::Set<T>& Utilities::Set<T>::operator+=(const Set<T>& other)
+Utilities::Set<T>& Utilities::Set<T>::operator+=(const Set<T>& other)
 {
     for (typename Set<T>::const_iterator i = other.begin();
          i != other.end(); ++i)
@@ -48,11 +48,11 @@ Utilities::Set<T>::Set<T>& Utilities::Se
 }
 
 template <class T>
-Utilities::Set<T>::Set<T>& Utilities::Set<T>::operator-=(const Set<T>& other)
+Utilities::Set<T>& Utilities::Set<T>::operator-=(const Set<T>& other)
 {
     for (typename Set<T>::const_iterator i = other.begin();
          i != other.end(); ++i)
-        erase(*i);
+        this->erase(*i);
     return *this;
 }
 
