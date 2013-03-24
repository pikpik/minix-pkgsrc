$NetBSD$

--- libcult-1.4.2/cult/mm/static-ptr.hxx.orig	2013-03-23 19:33:43.000000000 +0000
+++ libcult-1.4.2/cult/mm/static-ptr.hxx
@@ -60,7 +60,8 @@ namespace Cult
       static X*
       instance_ ()
       {
-        static X* i = new (KeyList ()) X;
+        KeyList k;
+        static X* i = new (k) X;
         return i;
       }
 
