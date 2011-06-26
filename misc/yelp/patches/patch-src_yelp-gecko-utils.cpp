$NetBSD$

* xulrunner-2 support.

--- src/yelp-gecko-utils.cpp.orig	2010-08-03 19:41:59.000000000 +0000
+++ src/yelp-gecko-utils.cpp
@@ -213,8 +213,8 @@ yelp_gecko_init (void)
 	nsresult rv;
 #ifdef XPCOM_GLUE
     static const GREVersionRange greVersion = {
-    "1.9a", PR_TRUE,
-    "2", PR_TRUE
+    "2.0a", PR_TRUE,
+    "2.0.*", PR_TRUE
     };
     char xpcomLocation[PATH_MAX];
     rv = GRE_GetGREPathWithProperties(&greVersion, 1, nsnull, 0, xpcomLocation, sizeof (xpcomLocation));
