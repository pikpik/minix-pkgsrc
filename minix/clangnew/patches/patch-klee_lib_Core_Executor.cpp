$NetBSD$

--- /usr/tmp/work/minix/clangnew/work/llvm/klee/lib/Core/Executor.cpp.orig	Thu Dec  8 00:55:55 2011
+++ /usr/tmp/work/minix/clangnew/work/llvm/klee/lib/Core/Executor.cpp
@@ -258,9 +258,6 @@ namespace {
 }
 
 
-static void *theMMap = 0;
-static unsigned theMMapSize = 0;
-
 namespace klee {
   RNG theRNG;
 }
@@ -3267,11 +3264,6 @@ void Executor::runFunctionAsMain(Function *f,
 
   if (statsTracker)
     statsTracker->done();
-
-  if (theMMap) {
-    munmap(theMMap, theMMapSize);
-    theMMap = 0;
-  }
 }
 
 unsigned Executor::getPathStreamID(const ExecutionState &state) {
