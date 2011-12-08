$NetBSD$

--- tools/clang/lib/Frontend/InitHeaderSearch.cpp.orig	Thu Nov 24 15:07:10 2011
+++ tools/clang/lib/Frontend/InitHeaderSearch.cpp
@@ -425,7 +425,7 @@ AddDefaultCPlusPlusIncludePaths(const llvm::Triple &tr
     break;
   }
   case llvm::Triple::Minix:
-    AddGnuCPlusPlusIncludePaths("/usr/gnu/include/c++/4.4.3",
+    AddGnuCPlusPlusIncludePaths("/usr/pkg/gcc44/include/c++/4.4.6",
                                 "", "", "", triple);
     break;
   case llvm::Triple::Solaris:
