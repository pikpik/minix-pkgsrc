$NetBSD$

--- /usr/tmp/work/minix/clang31/work/llvm/tools/clang/lib/Driver/Tools.cpp.orig	Tue Dec 13 13:58:51 2011
+++ /usr/tmp/work/minix/clang31/work/llvm/tools/clang/lib/Driver/Tools.cpp
@@ -4608,7 +4608,11 @@ void minix::Link::ConstructJob(Compilation &C, const J
 
   if (!Args.hasArg(options::OPT_nostdlib) &&
       !Args.hasArg(options::OPT_nostartfiles)) {
-      CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath("crt1.o")));
+      if (Args.hasArg(options::OPT_pg)) {
+        CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath("gcrt1.o")));
+      } else {
+        CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath("crt1.o")));
+      }
       CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath("crti.o")));
       CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath("crtbegin.o")));
       CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath("crtn.o")));
@@ -4632,11 +4636,13 @@ void minix::Link::ConstructJob(Compilation &C, const J
 
   if (!Args.hasArg(options::OPT_nostdlib) &&
       !Args.hasArg(options::OPT_nostartfiles)) {
-    if (Args.hasArg(options::OPT_pthread))
-      CmdArgs.push_back("-lpthread");
-    CmdArgs.push_back("-lc");
-    CmdArgs.push_back("-lCompilerRT-Generic");
-    CmdArgs.push_back("-L/usr/pkg/compiler-rt/lib");
+    if(!Args.hasArg(options::OPT_nodefaultlibs)) {
+      if (Args.hasArg(options::OPT_pthread))
+        CmdArgs.push_back("-lpthread");
+      CmdArgs.push_back("-lc");
+      CmdArgs.push_back("-lCompilerRT-Generic");
+      CmdArgs.push_back("-L/usr/pkg/compiler-rt/lib");
+    }
     CmdArgs.push_back(
 	 Args.MakeArgString(getToolChain().GetFilePath("crtend.o")));
   }
