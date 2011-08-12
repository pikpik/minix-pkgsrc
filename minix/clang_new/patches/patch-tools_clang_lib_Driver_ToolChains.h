$NetBSD$

--- tools/clang/lib/Driver/ToolChains.h.orig	Wed Aug 10 23:17:05 2011
+++ tools/clang/lib/Driver/ToolChains.h
@@ -340,7 +340,7 @@ class LLVM_LIBRARY_VISIBILITY NetBSD : public Generic_
                            const ActionList &Inputs) const;
 };
 
-class LLVM_LIBRARY_VISIBILITY Minix : public Generic_GCC {
+class LLVM_LIBRARY_VISIBILITY Minix : public Generic_ELF {
 public:
   Minix(const HostInfo &Host, const llvm::Triple& Triple);
 
