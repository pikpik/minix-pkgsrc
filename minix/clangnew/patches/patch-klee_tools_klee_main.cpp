$NetBSD$

--- /usr/tmp/work/minix/clangnew/work/llvm/klee/tools/klee/main.cpp.orig	Thu Dec  8 00:55:55 2011
+++ /usr/tmp/work/minix/clangnew/work/llvm/klee/tools/klee/main.cpp
@@ -51,6 +51,7 @@
 #include <fstream>
 #include <cerrno>
 #include <dirent.h>
+#include <unistd.h>
 #include <errno.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
@@ -1213,7 +1214,14 @@ int main(int argc, char **argv, char **envp) {  
       return r;
   }
 
+#if defined(KLEE_LIB_DIR) && defined(USE_KLEE_LIB_DIR)
+  /* KLEE_LIB_DIR is the lib dir of installed files as opposed to 
+   * where libs in the klee source tree are generated.
+   */
+  llvm::sys::Path LibraryDir(KLEE_LIB_DIR);
+#else
   llvm::sys::Path LibraryDir(KLEE_DIR "/" RUNTIME_CONFIGURATION "/lib");
+#endif
   Interpreter::ModuleOptions Opts(LibraryDir.c_str(),
                                   /*Optimize=*/OptimizeModule, 
                                   /*CheckDivZero=*/CheckDivZero);
