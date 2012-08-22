$NetBSD$

--- ld/emulparams/elf_i386_minix.sh.orig	Wed Aug 15 00:52:54 2012
+++ ld/emulparams/elf_i386_minix.sh
@@ -0,0 +1,3 @@
+. ${srcdir}/emulparams/elf_i386.sh
+. ${srcdir}/emulparams/elf_minix.sh
+OUTPUT_FORMAT="elf32-i386-minix"
