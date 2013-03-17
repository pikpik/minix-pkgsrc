--- test/bench_cascade.c.orig	Fri Nov  2 15:57:00 2012
+++ test/bench_cascade.c	Sun Mar 17 01:21:14 2013
@@ -139,7 +139,7 @@
 int
 main(int argc, char **argv)
 {
-#ifndef WIN32
+#if !defined(WIN32) && defined(HAVE_SETRLIMIT)
 	struct rlimit rl;
 #endif
 	int i, c;
@@ -157,7 +157,7 @@
 		}
 	}
 
-#ifndef WIN32
+#if !defined(WIN32) && defined(HAVE_SETRLIMIT)
 	rl.rlim_cur = rl.rlim_max = num_pipes * 2 + 50;
 	if (setrlimit(RLIMIT_NOFILE, &rl) == -1) {
 		perror("setrlimit");
