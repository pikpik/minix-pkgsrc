$NetBSD$

alloca.h is not portable.

--- extra/sigmund~/sigmund~.c.orig	2010-07-28 20:55:17.000000000 +0000
+++ extra/sigmund~/sigmund~.c
@@ -26,11 +26,7 @@ for example, defines this in the file d_
 #include <math.h>
 #include <stdio.h>
 #include <string.h>
-#ifdef _WIN32
 #include <malloc.h>
-#elif ! defined(_MSC_VER)
-#include <alloca.h>
-#endif
 #include <stdlib.h>
 #ifdef _MSC_VER
 #pragma warning( disable : 4244 )
