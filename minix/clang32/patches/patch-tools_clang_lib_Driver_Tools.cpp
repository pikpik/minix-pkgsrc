$NetBSD$

--- tools/clang/lib/Driver/Tools.cpp.orig	Wed Nov 21 07:56:23 2012
+++ tools/clang/lib/Driver/Tools.cpp
@@ -6154,6 +6154,33 @@ void minix::Link::ConstructJob(Compilation &C, const J
   const Driver &D = getToolChain().getDriver();
   ArgStringList CmdArgs;
 
+  if (!D.SysRoot.empty())
+    CmdArgs.push_back(Args.MakeArgString("--sysroot=" + D.SysRoot));
+
+  if (Args.hasArg(options::OPT_static)) {
+    CmdArgs.push_back("-Bstatic");
+  } else {
+    if (Args.hasArg(options::OPT_rdynamic))
+      CmdArgs.push_back("-export-dynamic");
+    CmdArgs.push_back("--eh-frame-hdr");
+    if (Args.hasArg(options::OPT_shared)) {
+      CmdArgs.push_back("-Bshareable");
+    } else {
+      CmdArgs.push_back("-dynamic-linker");
+      CmdArgs.push_back("/libexec/ld.elf_so");
+    }
+  }
+
+#if 0
+  // When building 32-bit code on NetBSD/amd64, we have to explicitly
+  // instruct ld in the base system to link 32-bit code.
+  if (ToolTriple.getArch() == llvm::Triple::x86_64 &&
+      getToolChain().getArch() == llvm::Triple::x86) {
+    CmdArgs.push_back("-m");
+    CmdArgs.push_back("elf_i386");
+  }
+#endif
+
   if (Output.isFilename()) {
     CmdArgs.push_back("-o");
     CmdArgs.push_back(Output.getFilename());
@@ -6163,42 +6190,86 @@ void minix::Link::ConstructJob(Compilation &C, const J
 
   if (!Args.hasArg(options::OPT_nostdlib) &&
       !Args.hasArg(options::OPT_nostartfiles)) {
-      CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath("crt1.o")));
-      CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath("crti.o")));
-      CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath("crtbegin.o")));
-      CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath("crtn.o")));
+    if (!Args.hasArg(options::OPT_shared)) {
+      CmdArgs.push_back(Args.MakeArgString(
+                              getToolChain().GetFilePath("crt0.o")));
+      CmdArgs.push_back(Args.MakeArgString(
+                              getToolChain().GetFilePath("crti.o")));
+      CmdArgs.push_back(Args.MakeArgString(
+                              getToolChain().GetFilePath("crtbegin.o")));
+    } else {
+      CmdArgs.push_back(Args.MakeArgString(
+                              getToolChain().GetFilePath("crti.o")));
+      CmdArgs.push_back(Args.MakeArgString(
+                              getToolChain().GetFilePath("crtbeginS.o")));
+    }
   }
 
   Args.AddAllArgs(CmdArgs, options::OPT_L);
   Args.AddAllArgs(CmdArgs, options::OPT_T_Group);
   Args.AddAllArgs(CmdArgs, options::OPT_e);
+  Args.AddAllArgs(CmdArgs, options::OPT_s);
+  Args.AddAllArgs(CmdArgs, options::OPT_t);
+  Args.AddAllArgs(CmdArgs, options::OPT_Z_Flag);
+  Args.AddAllArgs(CmdArgs, options::OPT_r);
 
   AddLinkerInputs(getToolChain(), Inputs, Args, CmdArgs);
 
-  addProfileRT(getToolChain(), Args, CmdArgs, getToolChain().getTriple());
-
   if (!Args.hasArg(options::OPT_nostdlib) &&
       !Args.hasArg(options::OPT_nodefaultlibs)) {
     if (D.CCCIsCXX) {
       getToolChain().AddCXXStdlibLibArgs(Args, CmdArgs);
       CmdArgs.push_back("-lm");
     }
-  }
 
-  if (!Args.hasArg(options::OPT_nostdlib) &&
-      !Args.hasArg(options::OPT_nostartfiles)) {
+#if 0
+    // FIXME: For some reason GCC passes -lgcc and -lgcc_s before adding
+    // the default system libraries. Just mimic this for now.
+    if (Args.hasArg(options::OPT_static)) {
+      CmdArgs.push_back("-lgcc_eh");
+    } else {
+      CmdArgs.push_back("--as-needed");
+      CmdArgs.push_back("-lgcc_s");
+      CmdArgs.push_back("--no-as-needed");
+    }
+    CmdArgs.push_back("-lgcc");
+#endif
+
     if (Args.hasArg(options::OPT_pthread))
       CmdArgs.push_back("-lpthread");
     CmdArgs.push_back("-lc");
-    CmdArgs.push_back("-lCompilerRT-Generic");
-    CmdArgs.push_back("-L/usr/pkg/compiler-rt/lib");
-    CmdArgs.push_back(
-	 Args.MakeArgString(getToolChain().GetFilePath("crtend.o")));
+
+#if 0
+    CmdArgs.push_back("-lgcc");
+    if (Args.hasArg(options::OPT_static)) {
+      CmdArgs.push_back("-lgcc_eh");
+    } else {
+      CmdArgs.push_back("--as-needed");
+      CmdArgs.push_back("-lgcc_s");
+      CmdArgs.push_back("--no-as-needed");
+    }
+#endif
   }
+  CmdArgs.push_back("-L/usr/pkg/compiler-rt/lib -lCompilerRT-Generic");
 
+  if (!Args.hasArg(options::OPT_nostdlib) &&
+      !Args.hasArg(options::OPT_nostartfiles)) {
+    if (!Args.hasArg(options::OPT_shared))
+      CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath(
+                                                                  "crtend.o")));
+    else
+      CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath(
+                                                                 "crtendS.o")));
+    CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath(
+                                                                    "crtn.o")));
+  }
+
+  addProfileRT(getToolChain(), Args, CmdArgs, getToolChain().getTriple());
+
   const char *Exec = Args.MakeArgString(getToolChain().GetProgramPath("ld"));
   C.addCommand(new Command(JA, *this, Exec, CmdArgs));
 }
+
 
 /// DragonFly Tools
 
