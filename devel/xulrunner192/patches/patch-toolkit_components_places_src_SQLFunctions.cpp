$NetBSD$

--- toolkit/components/places/src/SQLFunctions.cpp.orig	2012-11-17 18:28:05.000000000 +0000
+++ toolkit/components/places/src/SQLFunctions.cpp
@@ -122,8 +122,8 @@ namespace places {
     if (aSourceString.IsEmpty())
       return false;
 
-    // Define a const instance of this class so it is created once.
-    const nsCaseInsensitiveStringComparator caseInsensitiveCompare;
+    // Define a static instance of this class so it is created once.
+    static nsCaseInsensitiveStringComparator caseInsensitiveCompare;
 
     const_wchar_iterator tokenStart(aToken.BeginReading()),
                          tokenEnd(aToken.EndReading()),
