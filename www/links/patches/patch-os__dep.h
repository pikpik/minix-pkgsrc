$NetBSD$

--- os_dep.h.orig	Wed Dec 26 03:13:05 2007
+++ os_dep.h
@@ -53,7 +53,7 @@ static inline int dir_sep(char x) { return x == '/'; }
 #define DEFAULT_SHELL "/bin/sh"
 #define GETSHELL getenv("SHELL")
 #define SHARED_CONFIG_DIR "/etc/"
-#ifdef HAVE_SYS_UN_H
+#if defined(HAVE_SYS_UN_H) && ! defined(__minix)
 #define USE_AF_UNIX
 #else
 #define DONT_USE_AF_UNIX
