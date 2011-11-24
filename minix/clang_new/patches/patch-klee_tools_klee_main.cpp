$NetBSD$

--- klee/tools/klee/main.cpp.orig	Thu Nov 24 15:07:24 2011
+++ klee/tools/klee/main.cpp
@@ -51,6 +51,7 @@
 #include <fstream>
 #include <cerrno>
 #include <dirent.h>
+#include <unistd.h>
 #include <errno.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
@@ -1213,7 +1214,11 @@ int main(int argc, char **argv, char **envp) {  
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
