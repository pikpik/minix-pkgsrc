$NetBSD: patch-mozilla_ipc_glue_GeckoChildProcessHost.cpp,v 1.6 2013/01/07 21:55:30 ryoon Exp $

--- mozilla/ipc/glue/GeckoChildProcessHost.cpp.orig	2013-01-06 06:26:17.000000000 +0000
+++ mozilla/ipc/glue/GeckoChildProcessHost.cpp
@@ -4,7 +4,13 @@
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
+#if defined(__NetBSD__)
+_Pragma("GCC visibility push(default)")
+#endif
 #include "GeckoChildProcessHost.h"
+#if defined(__NetBSD__)
+_Pragma("GCC visibility pop")
+#endif
 
 #include "base/command_line.h"
 #include "base/path_service.h"
