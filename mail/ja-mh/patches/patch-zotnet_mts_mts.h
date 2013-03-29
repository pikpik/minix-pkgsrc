$NetBSD$

--- zotnet/mts/mts.h.orig	2013-03-28 18:05:39.000000000 +0000
+++ zotnet/mts/mts.h
@@ -109,3 +109,5 @@ extern char *maildelivery;
 
 extern int Everyone;
 extern char *NoShell;
+
+void mts_init (char *name);
