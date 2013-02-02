$NetBSD$

--- clients/uil/UilDB.c.orig	2012-10-22 14:50:39.000000000 +0000
+++ clients/uil/UilDB.c
@@ -66,7 +66,16 @@ static char rcsid[] = "$XConsortium: Uil
 #include <unistd.h>
 #endif
 
-
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#  if __NetBSD_Version__ >= 299001000 /* NetBSD 2.99.10 has getpw*_r*/
+#    if !defined(_POSIX_THREAD_SAFE_FUNCTIONS)
+#      define _POSIX_THREAD_SAFE_FUNCTIONS 200112L
+#    endif
+#  else
+#    define XNO_MTSAFE_PWDAPI
+#  endif
+#endif
 
 
 #include "UilDefI.h"
