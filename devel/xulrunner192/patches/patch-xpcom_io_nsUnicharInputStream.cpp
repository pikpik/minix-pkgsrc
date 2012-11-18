$NetBSD$

--- xpcom/io/nsUnicharInputStream.cpp.orig	2012-11-17 15:54:14.000000000 +0000
+++ xpcom/io/nsUnicharInputStream.cpp
@@ -463,5 +463,5 @@ nsSimpleUnicharStreamFactory::GetInstanc
   return const_cast<nsSimpleUnicharStreamFactory*>(&kInstance);
 }
 
-const nsSimpleUnicharStreamFactory
+nsSimpleUnicharStreamFactory
 nsSimpleUnicharStreamFactory::kInstance;
