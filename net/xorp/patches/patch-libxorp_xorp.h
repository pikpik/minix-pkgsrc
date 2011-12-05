$NetBSD$

--- libxorp/xorp.h.orig	2011-12-05 19:51:40.000000000 +0000
+++ libxorp/xorp.h
@@ -173,9 +173,7 @@ using namespace std::rel_ops;
 #define FALSE (0)
 #define TRUE (!FALSE)
 #endif /* TRUE, FALSE */
-#ifndef __cplusplus
-typedef enum { true = TRUE, false = FALSE } bool;
-#endif
+#include <stdbool.h>
 typedef bool bool_t;
 
 /*
