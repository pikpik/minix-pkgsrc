$NetBSD$

--- tools/clang/lib/Driver/Tools.cpp.orig	Thu Dec  8 12:10:22 2011
+++ tools/clang/lib/Driver/Tools.cpp
@@ -4596,7 +4596,11 @@ void minix::Link::ConstructJob(Compilation &C, const J
 
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
