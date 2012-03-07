$NetBSD$

--- dist/include/prop/prop_bool.h.orig	2008-02-29 19:25:58.000000000 +0100
+++ dist/include/prop/prop_bool.h	2012-03-02 20:18:07.993901094 +0100
@@ -43,6 +43,8 @@
 
 typedef struct _prop_bool *prop_bool_t;
 
+#include <sys/cdefs.h>
+
 __BEGIN_DECLS
 prop_bool_t	prop_bool_create(bool);
 prop_bool_t	prop_bool_copy(prop_bool_t);
