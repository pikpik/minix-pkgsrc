$NetBSD$

alloca.h is not portable.

--- src/x_list.c.orig	2010-07-21 18:37:47.000000000 +0000
+++ src/x_list.c
@@ -4,11 +4,7 @@
 
 #include "m_pd.h"
 /* #include <string.h> */
-#ifdef MSW
 #include <malloc.h>
-#else
-#include <alloca.h>
-#endif
 
 extern t_pd *newest;
 
