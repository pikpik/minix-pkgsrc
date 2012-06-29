$NetBSD$

--- plugins/symbol-browser/test-class.h.orig	2012-06-25 13:40:35.000000000 +0000
+++ plugins/symbol-browser/test-class.h
@@ -72,7 +72,7 @@ class YourClass {
 
 
 public:
-	YourClass ();
+	YourClass () {};
 	YourClass (int par1, char* par2);
 
 	void yc_first_function( int par1, char** par2);
