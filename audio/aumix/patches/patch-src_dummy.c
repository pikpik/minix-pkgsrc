$NetBSD$

--- src/dummy.c.orig	Mon Jun 26 22:51:42 2000
+++ src/dummy.c	Tue Jul 11 10:01:19 2000
@@ -1,7 +1,7 @@
 /* dummy.c: implement a dummy mixer for debugging on machines without
  *          sound card
  */
-#include "common.h"
+#include "./common.h"
 #ifdef DUMMY_MIXER
 #define	DUMMY_DEVMASK	 0x01FFFFFF
 #define	DUMMY_RECMASK	 0x00000040
