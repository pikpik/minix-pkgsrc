--- test/bench.c.orig	Fri Nov  2 15:57:00 2012
+++ test/bench.c	Sun Mar 17 00:55:12 2013
@@ -125,7 +125,7 @@
 int
 main(int argc, char **argv)
 {
-#ifndef WIN32
+#if !defined(WIN32) && defined(HAVE_SETRLIMIT)
 	struct rlimit rl;
 #endif
 	int i, c;
@@ -156,7 +156,7 @@
 		}
 	}
 
-#ifndef WIN32
+#if !defined(WIN32) && defined(HAVE_SETRLIMIT)
 	rl.rlim_cur = rl.rlim_max = num_pipes * 2 + 50;
 	if (setrlimit(RLIMIT_NOFILE, &rl) == -1) {
 		perror("setrlimit");
