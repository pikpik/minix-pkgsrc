$NetBSD$

--- tools/clang/lib/Basic/Targets.cpp.orig	Thu Jun 28 00:57:41 2012
+++ tools/clang/lib/Basic/Targets.cpp
@@ -289,12 +289,6 @@ class MinixTargetInfo : public OSTargetInfo<Target> { 
     // Minix defines
 
     Builder.defineMacro("__minix", "3");
-    Builder.defineMacro("_EM_WSIZE", "4");
-    Builder.defineMacro("_EM_PSIZE", "4");
-    Builder.defineMacro("_EM_SSIZE", "2");
-    Builder.defineMacro("_EM_LSIZE", "4");
-    Builder.defineMacro("_EM_FSIZE", "4");
-    Builder.defineMacro("_EM_DSIZE", "8");
     Builder.defineMacro("__ELF__");
     DefineStd(Builder, "unix", Opts);
   }
