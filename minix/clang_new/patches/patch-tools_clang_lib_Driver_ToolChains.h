$NetBSD$

--- tools/clang/lib/Driver/ToolChains.h.orig	Thu Nov 24 15:07:23 2011
+++ tools/clang/lib/Driver/ToolChains.h
@@ -450,7 +450,7 @@ class LLVM_LIBRARY_VISIBILITY NetBSD : public Generic_
                            const ActionList &Inputs) const;
 };
 
-class LLVM_LIBRARY_VISIBILITY Minix : public Generic_GCC {
+class LLVM_LIBRARY_VISIBILITY Minix : public Generic_ELF {
 public:
   Minix(const HostInfo &Host, const llvm::Triple& Triple);
 
