$NetBSD$

--- fixincludes/mkfixinc.sh.orig	Tue Aug 28 15:53:39 2012
+++ fixincludes/mkfixinc.sh
@@ -16,6 +16,7 @@ case $machine in
     x86_64-*-mingw32* | \
     i?86-*-interix* | \
     *-*-vxworks* | \
+    *-*-minix* | \
     powerpc-*-eabisim* | \
     powerpc-*-eabi*    | \
     powerpc-*-rtems*   | \
