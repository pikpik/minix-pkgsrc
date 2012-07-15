$NetBSD$

--- coda-src/resolution/rename.cc.orig	2012-07-15 02:02:52.000000000 +0000
+++ coda-src/resolution/rename.cc
@@ -51,6 +51,10 @@ extern "C" {
 #include "rsle.h"
 #include "resstats.h"
 
+#ifndef MAXNAMLEN
+#define MAXNAMLEN 255
+#endif
+
 static void AddToIncList(dlist *, dlist *, Volume *, ViceFid *, int =0);
 static int CheckResolveRenameSemantics(rsle *, Volume *, ViceFid *, dlist *, vle **, vle **, vle **, 
 					vle **,olist *, dlist *, dlist *, int *);
