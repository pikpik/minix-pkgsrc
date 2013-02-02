$NetBSD$

Chase after the C++ standard:
   - string constants are const char *

--- src/sw.hxx~	1998-12-10 05:35:06.000000000 +0000
+++ src/sw.hxx
@@ -2,7 +2,7 @@
 #define SW_HXX
 
 // 400 words
-char   *stoplist[] = {
+const char   *stoplist[] = {
   "0",
   "1",
   "2",
