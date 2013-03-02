$NetBSD$

--- src/bin/animate/glob.c.orig	2013-03-01 21:51:25.000000000 +0000
+++ src/bin/animate/glob.c
@@ -38,6 +38,7 @@ static char sccsid[] = "@(#)glob.c	5.7 (
 #include <stdio.h>
 #include <errno.h>
 #include <pwd.h>
+#include <string.h>
 
 #if !defined(dirfd) && !defined(__GLIBC__) && !defined(__linux__) && !defined(__FreeBSD__)
 #define dirfd(dirp)  ((dirp)->dd_fd)
