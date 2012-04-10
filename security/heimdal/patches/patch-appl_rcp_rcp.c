$NetBSD$

--- appl/rcp/rcp.c.orig	Tue Jan 10 21:53:51 2012
+++ appl/rcp/rcp.c
@@ -551,9 +551,11 @@ sink(int argc, char **argv)
 			sink(1, vect);
 			if (setimes) {
 				setimes = 0;
+#ifndef __minix
 				if (utimes(np, tv) < 0)
 				    run_err("%s: set times: %s",
 					np, strerror(errno));
+#endif
 			}
 			if (mod_flag)
 				chmod(np, mode);
@@ -621,11 +623,13 @@ bad:			run_err("%s: %s", np, strerror(errno));
 		response();
 		if (setimes && wrerr == NO) {
 			setimes = 0;
+#ifndef __minix
 			if (utimes(np, tv) < 0) {
 				run_err("%s: set times: %s",
 				    np, strerror(errno));
 				wrerr = DISPLAYED;
 			}
+#endif
 		}
 		switch(wrerr) {
 		case YES:
