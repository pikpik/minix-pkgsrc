$NetBSD$

--- klee/lib/Core/Executor.cpp.orig	Thu Aug 11 01:14:44 2011
+++ klee/lib/Core/Executor.cpp
@@ -3268,10 +3268,14 @@ void Executor::runFunctionAsMain(Function *f,
   if (statsTracker)
     statsTracker->done();
 
+#ifdef __minix
+	assert(!theMMap);
+#else
   if (theMMap) {
     munmap(theMMap, theMMapSize);
     theMMap = 0;
   }
+#endif
 }
 
 unsigned Executor::getPathStreamID(const ExecutionState &state) {
