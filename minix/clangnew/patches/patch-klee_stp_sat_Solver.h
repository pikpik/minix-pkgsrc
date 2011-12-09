$NetBSD$

--- /usr/tmp/work/minix/clangnew/work/llvm/klee/stp/sat/Solver.h.orig	Thu Dec  8 00:55:55 2011
+++ /usr/tmp/work/minix/clangnew/work/llvm/klee/stp/sat/Solver.h
@@ -315,9 +315,14 @@ static inline int64 memUsed() {
 #include <sys/resource.h>
 
 static inline double cpuTime(void) {
+#ifndef RUSAGE_SELF
+	return 0;
+#else
     struct rusage ru;
     getrusage(RUSAGE_SELF, &ru);
-    return (double)ru.ru_utime.tv_sec + (double)ru.ru_utime.tv_usec / 1000000; }
+    return (double)ru.ru_utime.tv_sec + (double)ru.ru_utime.tv_usec / 1000000;
+#endif
+    }
 
 #if defined(__linux__) || defined(__CYGWIN__)
 static inline int memReadStat(int field)
@@ -342,9 +347,14 @@ static inline int64 memUsed() { return (int64)memReadS
 //defined(__FreeBSD__)
 
 static inline int64 memUsed(void) {
+#ifndef RUSAGE_SELF
+	return 0;
+#else
     struct rusage ru;
     getrusage(RUSAGE_SELF, &ru);
-    return ru.ru_maxrss*1024; }
+    return ru.ru_maxrss*1024;
+#endif
+    }
 
 #endif
 
