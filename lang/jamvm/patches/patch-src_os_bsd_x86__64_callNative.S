$NetBSD$

--- src/os/bsd/x86_64/callNative.S.orig	2013-02-25 20:16:25.000000000 +0000
+++ src/os/bsd/x86_64/callNative.S
@@ -24,7 +24,7 @@
 .text
 .align  2
 .global callJNIMethod
-.type   callJNIMethod,function
+.type   callJNIMethod,@function
 
 /*
  * Arguments passed in:
