$NetBSD$

--- tools/clang/lib/Driver/ToolChains.cpp.orig	Wed Aug 10 23:17:05 2011
+++ tools/clang/lib/Driver/ToolChains.cpp
@@ -1239,11 +1239,9 @@ Tool &NetBSD::SelectTool(const Compilation &C, const J
 /// Minix - Minix tool chain which can call as(1) and ld(1) directly.
 
 Minix::Minix(const HostInfo &Host, const llvm::Triple& Triple)
-  : Generic_GCC(Host, Triple) {
+  : Generic_ELF(Host, Triple) {
   getFilePaths().push_back(getDriver().Dir + "/../lib");
   getFilePaths().push_back("/usr/lib");
-  getFilePaths().push_back("/usr/gnu/lib");
-  getFilePaths().push_back("/usr/gnu/lib/gcc/i686-pc-minix/4.4.3");
 }
 
 Tool &Minix::SelectTool(const Compilation &C, const JobAction &JA,
