$NetBSD$

--- layout/style/nsCSSRuleProcessor.cpp.orig	2012-11-17 18:19:14.000000000 +0000
+++ layout/style/nsCSSRuleProcessor.cpp
@@ -1196,7 +1196,7 @@ static PRBool AttrMatchesValue(const nsA
     return PR_FALSE;
 
   const nsDefaultStringComparator defaultComparator;
-  const nsCaseInsensitiveStringComparator ciComparator;
+  nsCaseInsensitiveStringComparator ciComparator;
   const nsStringComparator& comparator = aAttrSelector->mCaseSensitive
                 ? static_cast<const nsStringComparator&>(defaultComparator)
                 : static_cast<const nsStringComparator&>(ciComparator);
