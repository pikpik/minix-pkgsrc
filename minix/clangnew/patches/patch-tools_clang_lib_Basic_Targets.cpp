$NetBSD$

--- tools/clang/lib/Basic/Targets.cpp.orig	Thu Nov 24 15:07:11 2011
+++ tools/clang/lib/Basic/Targets.cpp
@@ -298,6 +298,7 @@ class MinixTargetInfo : public OSTargetInfo<Target> { 
     Builder.defineMacro("_EM_LSIZE", "4");
     Builder.defineMacro("_EM_FSIZE", "4");
     Builder.defineMacro("_EM_DSIZE", "8");
+    Builder.defineMacro("__ELF__");
     DefineStd(Builder, "unix", Opts);
   }
 public:
