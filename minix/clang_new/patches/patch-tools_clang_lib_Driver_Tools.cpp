$NetBSD$

--- tools/clang/lib/Driver/Tools.cpp.orig	Wed Aug 10 23:17:05 2011
+++ tools/clang/lib/Driver/Tools.cpp
@@ -3379,7 +3379,7 @@ void auroraux::Assemble::ConstructJob(Compilation &C, 
   }
 
   const char *Exec =
-    Args.MakeArgString(getToolChain().GetProgramPath("gas"));
+    Args.MakeArgString(getToolChain().GetProgramPath("as"));
   C.addCommand(new Command(JA, *this, Exec, CmdArgs));
 }
 
@@ -4182,7 +4182,7 @@ void minix::Assemble::ConstructJob(Compilation &C, con
   }
 
   const char *Exec =
-    Args.MakeArgString(getToolChain().GetProgramPath("gas"));
+    Args.MakeArgString(getToolChain().GetProgramPath("as"));
   C.addCommand(new Command(JA, *this, Exec, CmdArgs));
 }
 
@@ -4202,9 +4202,14 @@ void minix::Link::ConstructJob(Compilation &C, const J
   }
 
   if (!Args.hasArg(options::OPT_nostdlib) &&
-      !Args.hasArg(options::OPT_nostartfiles))
-    CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath(
-                                                      "/usr/gnu/lib/crtso.o")));
+      !Args.hasArg(options::OPT_nostartfiles)) {
+      CmdArgs.push_back(
+	 Args.MakeArgString(getToolChain().GetFilePath("crt1.o")));
+      CmdArgs.push_back(
+	 Args.MakeArgString(getToolChain().GetFilePath("crti.o")));
+      CmdArgs.push_back(
+	 Args.MakeArgString(getToolChain().GetFilePath("crtn.o")));
+  }
 
   Args.AddAllArgs(CmdArgs, options::OPT_L);
   Args.AddAllArgs(CmdArgs, options::OPT_T_Group);
@@ -4212,6 +4217,8 @@ void minix::Link::ConstructJob(Compilation &C, const J
 
   AddLinkerInputs(getToolChain(), Inputs, Args, CmdArgs);
 
+  addProfileRT(getToolChain(), Args, CmdArgs, getToolChain().getTriple());
+
   if (!Args.hasArg(options::OPT_nostdlib) &&
       !Args.hasArg(options::OPT_nodefaultlibs)) {
     if (D.CCCIsCXX) {
@@ -4222,23 +4229,12 @@ void minix::Link::ConstructJob(Compilation &C, const J
     if (Args.hasArg(options::OPT_pthread))
       CmdArgs.push_back("-lpthread");
     CmdArgs.push_back("-lc");
-    CmdArgs.push_back("-lgcc");
-    CmdArgs.push_back("-L/usr/gnu/lib");
-    // FIXME: fill in the correct search path for the final
-    // support libraries.
-    CmdArgs.push_back("-L/usr/gnu/lib/gcc/i686-pc-minix/4.4.3");
+    CmdArgs.push_back("-lCompilerRT-Generic");
+    CmdArgs.push_back("-L/usr/pkg/lib");
   }
 
-  if (!Args.hasArg(options::OPT_nostdlib) &&
-      !Args.hasArg(options::OPT_nostartfiles)) {
-    CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath(
-                                              "/usr/gnu/lib/libend.a")));
-  }
-
-  addProfileRT(getToolChain(), Args, CmdArgs, getToolChain().getTriple());
-
   const char *Exec =
-    Args.MakeArgString(getToolChain().GetProgramPath("/usr/gnu/bin/gld"));
+    Args.MakeArgString(getToolChain().GetProgramPath("/usr/pkg/bin/ld"));
   C.addCommand(new Command(JA, *this, Exec, CmdArgs));
 }
 
