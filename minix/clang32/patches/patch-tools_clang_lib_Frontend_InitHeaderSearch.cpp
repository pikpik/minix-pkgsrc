$NetBSD$

--- tools/clang/lib/Frontend/InitHeaderSearch.cpp.orig	Thu Jun 28 00:57:40 2012
+++ tools/clang/lib/Frontend/InitHeaderSearch.cpp
@@ -421,7 +421,7 @@ AddDefaultCPlusPlusIncludePaths(const llvm::Triple &tr
     break;
   }
   case llvm::Triple::Minix:
-    AddGnuCPlusPlusIncludePaths("/usr/gnu/include/c++/4.4.3",
+    AddGnuCPlusPlusIncludePaths("/usr/pkg/gcc44/include/c++/4.4.6",
                                 "", "", "", triple);
     break;
   case llvm::Triple::Solaris:
