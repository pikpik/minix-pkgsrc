$NetBSD$

--- bfd/targets.c.orig	Fri Oct 22 12:08:28 2010
+++ bfd/targets.c
@@ -749,6 +749,7 @@ extern const bfd_target i386linux_vec;
 extern const bfd_target i386lynx_aout_vec;
 extern const bfd_target i386lynx_coff_vec;
 extern const bfd_target i386mach3_vec;
+extern const bfd_target bfd_elf32_i386_minix_vec;
 extern const bfd_target i386msdos_vec;
 extern const bfd_target i386netbsd_vec;
 extern const bfd_target i386os9k_vec;
