$NetBSD$

--- programs/Xserver/hw/xfree86/os-support/minix3/dummy.c.orig	Mon Aug  1 16:09:19 2011
+++ programs/Xserver/hw/xfree86/os-support/minix3/dummy.c
@@ -37,5 +37,8 @@ xf86KbdInit()
 
 int finite(double dsrc)
 {
+	return isfinite(dsrc);
+	/*
 	FatalError("finite not implemented\n");
+	*/
 }
