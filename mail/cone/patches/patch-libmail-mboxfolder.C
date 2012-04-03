$NetBSD$

Use stdio functions to ensure that the mail::file cast to FILE * happens.

--- libmail/mboxfolder.C.orig	2011-11-22 16:30:20.000000000 +0000
+++ libmail/mboxfolder.C
@@ -40,6 +40,8 @@
 
 #include <vector>
 
+#undef feof
+
 using namespace std;
 
 mail::mbox::folder::folder(string pathArg,
