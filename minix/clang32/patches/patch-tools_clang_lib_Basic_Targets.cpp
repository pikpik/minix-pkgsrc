$NetBSD$

--- tools/clang/lib/Basic/Targets.cpp.orig	Wed Nov 28 22:01:30 2012
+++ tools/clang/lib/Basic/Targets.cpp
@@ -292,12 +292,6 @@ class MinixTargetInfo : public OSTargetInfo<Target> { 
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
