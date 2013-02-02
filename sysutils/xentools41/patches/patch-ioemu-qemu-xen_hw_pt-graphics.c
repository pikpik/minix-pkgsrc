$NetBSD: patch-libxl_libxl_create.c,v 1.1 2011/10/29 14:16:53 jmcneill Exp $

--- ioemu-qemu-xen/hw/pt-graphics.c.orig	2012-05-24 16:16:49.000000000 +0200
+++ ioemu-qemu-xen/hw/pt-graphics.c	2012-05-24 16:16:55.000000000 +0200
@@ -3,8 +3,6 @@
  */
 
 #include "pass-through.h"
-#include "pci/header.h"
-#include "pci/pci.h"
 
 #include <unistd.h>
 #include <sys/ioctl.h>
