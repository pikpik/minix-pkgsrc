$NetBSD$

--- contrib/dblink/dblink.c.orig	2012-09-19 21:47:58.000000000 +0000
+++ contrib/dblink/dblink.c
@@ -46,7 +46,7 @@
 #include "parser/scansup.h"
 #include "utils/acl.h"
 #include "utils/builtins.h"
-#include "utils/fmgroids.h"
+#include "postgresql/server/utils/fmgroids.h"
 #include "utils/lsyscache.h"
 #include "utils/memutils.h"
 #include "utils/rel.h"
