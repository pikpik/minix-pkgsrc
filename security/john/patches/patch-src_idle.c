--- src/idle.c.orig	Fri Dec 25 20:32:45 2009
+++ src/idle.c	Fri Mar 15 00:03:41 2013
@@ -91,7 +91,9 @@
 	do {
 		if (event_pending) break;
 		last_check = current;
+#ifndef __minix
 		sched_yield();
+#endif
 		yield_calls++;
 		current = times(&buf);
 	} while (current - last_check > 1 && current - last_adj < clk_tck);
