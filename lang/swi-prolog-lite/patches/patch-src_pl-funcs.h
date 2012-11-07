$NetBSD$

Don't change visibility of a system prototype.

--- src/pl-funcs.h.orig	2012-11-04 22:29:01.000000000 +0000
+++ src/pl-funcs.h
@@ -426,7 +426,9 @@ COMMON(void) 		RemoveTemporaryFiles(void
 COMMON(bool) 		OpenStream(int fd);
 COMMON(bool) 		expandVars(const char *pattern, char *expanded, int len);
 COMMON(char *) 		ExpandOneFile(const char *spec, char *file);
+#ifndef HAVE_GETWD
 COMMON(char *) 		getwd(char *buf);
+#endif
 COMMON(char *) 		AbsoluteFile(const char *spec, char *path);
 COMMON(int) 		IsAbsolutePath(const char *spec);
 COMMON(char *) 		BaseName(const char *f);
