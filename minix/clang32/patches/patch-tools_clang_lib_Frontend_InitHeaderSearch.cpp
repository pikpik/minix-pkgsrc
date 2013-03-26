$NetBSD$

--- tools/clang/lib/Frontend/InitHeaderSearch.cpp.orig	Wed Oct 24 16:19:39 2012
+++ tools/clang/lib/Frontend/InitHeaderSearch.cpp
@@ -427,7 +427,7 @@ AddDefaultCPlusPlusIncludePaths(const llvm::Triple &tr
     break;
   }
   case llvm::Triple::Minix:
-    AddGnuCPlusPlusIncludePaths("/usr/gnu/include/c++/4.4.3",
+    AddGnuCPlusPlusIncludePaths("/usr/pkg/gcc44/include/c++/4.4.6",
                                 "", "", "", triple);
     break;
   case llvm::Triple::Solaris:
