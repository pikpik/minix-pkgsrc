$NetBSD$

Remove obsolete __sun__ barrier, SunOS has stdbool.h now.

--- jack/control.h.orig	2011-06-23 15:09:05.000000000 +0000
+++ jack/control.h
@@ -31,9 +31,7 @@
 
 #include <jack/jslist.h>
 
-#if !defined (__sun__)
 #include <stdbool.h>
-#endif
 
 /** Parameter types, intentionally similar to jack_driver_param_type_t */
 typedef enum
