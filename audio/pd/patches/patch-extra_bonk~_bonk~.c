$NetBSD$

alloca.h is not portable.

--- extra/bonk~/bonk~.c.orig	2010-08-19 01:37:00.000000000 +0000
+++ extra/bonk~/bonk~.c
@@ -82,11 +82,7 @@ void *bonk_class;
 static t_class *bonk_class;
 #endif
 
-#ifdef _WIN32
 #include <malloc.h>
-#elif ! defined(_MSC_VER)
-#include <alloca.h>
-#endif
 
 /* ------------------------ bonk~ ----------------------------- */
 
