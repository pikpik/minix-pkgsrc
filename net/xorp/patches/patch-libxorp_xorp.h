$NetBSD: patch-libxorp_xorp.h,v 1.1 2011/12/05 22:54:57 joerg Exp $

--- libxorp/xorp.h.orig	2009-01-05 18:30:58.000000000 +0000
+++ libxorp/xorp.h
@@ -39,6 +39,7 @@
 #endif
 
 #if defined (__cplusplus) && !defined(__STL_NO_NAMESPACES)
+namespace std {};
 using namespace std;
 #endif
 
@@ -173,9 +174,7 @@ using namespace std::rel_ops;
 #define FALSE (0)
 #define TRUE (!FALSE)
 #endif /* TRUE, FALSE */
-#ifndef __cplusplus
-typedef enum { true = TRUE, false = FALSE } bool;
-#endif
+#include <stdbool.h>
 typedef bool bool_t;
 
 /*
