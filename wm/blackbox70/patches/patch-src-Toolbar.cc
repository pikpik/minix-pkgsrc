$NetBSD$

Fix build failure when time_t is 64 bits on a 32-bit machine.

--- src/Toolbar.cc~	2005-04-12 07:38:00.000000000 +0000
+++ src/Toolbar.cc
@@ -43,8 +43,10 @@
 long nextTimeout(int resolution)
 {
   timeval now;
+  int secs;
   gettimeofday(&now, 0);
-  return (std::max(1000l, ((((resolution - (now.tv_sec % resolution)) * 1000l))
+  secs = now.tv_sec % resolution;
+  return (std::max(1000l, ((((resolution - secs) * 1000l))
                            - (now.tv_usec / 1000l))));
 }
 
