$NetBSD$

--- src/sat/utils/System.h.orig	Tue Dec 13 02:40:23 2011
+++ src/sat/utils/System.h
@@ -51,9 +51,14 @@ static inline double Minisat::cpuTime(void) { return (
 #include <unistd.h>
 
 static inline double Minisat::cpuTime(void) {
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
 
