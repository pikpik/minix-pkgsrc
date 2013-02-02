$NetBSD$

--- plugins/symbol-browser/test-class.cpp.orig	2012-06-25 13:38:23.000000000 +0000
+++ plugins/symbol-browser/test-class.cpp
@@ -10,12 +10,11 @@ typedef struct _faa_1 {
  
 MyClass *klass;
 
- 
 //klass->
 
 int func_test1() {
 
-	YourClass klass();
+	YourClass klass;
 
 	
 
