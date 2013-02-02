$NetBSD: patch-aa,v 1.2 2011/05/07 18:39:06 tnn Exp $

--- ioemu-qemu-xen/hw/pass-through.h.orig	2012-05-24 15:57:12.000000000 +0200
+++ ioemu-qemu-xen/hw/pass-through.h	2012-05-24 15:58:46.000000000 +0200
@@ -20,8 +20,13 @@
 
 #include "hw.h"
 #include "pci.h"
+#ifdef __NetBSD__
+#include "pciutils/header.h"
+#include "pciutils/pci.h"
+#else
 #include "pci/header.h"
 #include "pci/pci.h"
+#endif
 #include "exec-all.h"
 #include "sys-queue.h"
 #include "qemu-timer.h"
