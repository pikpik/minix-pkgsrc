$NetBSD$

--- src/sat/cryptominisat2/time_mem.h.orig	Tue Dec 13 02:40:22 2011
+++ src/sat/cryptominisat2/time_mem.h
@@ -43,9 +43,14 @@ static inline double cpuTime(void) {
 #else
 
 static inline double cpuTime(void) {
+#ifdef RUSAGE_SELF
     struct rusage ru;
     getrusage(RUSAGE_SELF, &ru);
-    return (double)ru.ru_utime.tv_sec + (double)ru.ru_utime.tv_usec / 1000000; }
+    return (double)ru.ru_utime.tv_sec + (double)ru.ru_utime.tv_usec / 1000000;
+#else
+    return (double)0.0;
+#endif
+}
 #endif
 
 #if defined(__linux__)
