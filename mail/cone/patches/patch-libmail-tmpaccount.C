$NetBSD: patch-libmail-tmpaccount.C,v 1.1 2011/11/22 18:12:35 joerg Exp $

Use stdio functions to ensure that the mail::file cast to FILE * happens.

--- libmail/tmpaccount.C.orig	2011-04-04 11:58:20.000000000 +0000
+++ libmail/tmpaccount.C
@@ -12,6 +12,8 @@
 #include <sys/stat.h>
 #include <cstring>
 
+#undef ferror
+
 using namespace std;
 
 LIBMAIL_START
