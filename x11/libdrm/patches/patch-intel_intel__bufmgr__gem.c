$NetBSD$

ETIME is not defined on DragonFly BSD, work around it.

--- intel/intel_bufmgr_gem.c.orig	2012-07-02 15:22:14.326942000 +0000
+++ intel/intel_bufmgr_gem.c
@@ -54,6 +54,9 @@
 #include <stdbool.h>

 #include "errno.h"
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 #include "libdrm_lists.h"
 #include "intel_bufmgr.h"
 #include "intel_bufmgr_priv.h"
