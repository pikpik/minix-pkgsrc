$NetBSD$

--- klee/tools/klee/main.cpp.orig	Thu Aug 11 01:14:44 2011
+++ klee/tools/klee/main.cpp
@@ -47,6 +47,7 @@
 #include <fstream>
 #include <cerrno>
 #include <dirent.h>
+#include <unistd.h>
 #include <errno.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
@@ -1209,7 +1210,11 @@ int main(int argc, char **argv, char **envp) {  
       return r;
   }
 
+#ifdef KLEE_LIB_DIR
+  llvm::sys::Path LibraryDir(KLEE_LIB_DIR);
+#else
   llvm::sys::Path LibraryDir(KLEE_DIR "/" RUNTIME_CONFIGURATION "/lib");
+#endif
   Interpreter::ModuleOptions Opts(LibraryDir.c_str(),
                                   /*Optimize=*/OptimizeModule, 
                                   /*CheckDivZero=*/CheckDivZero);
