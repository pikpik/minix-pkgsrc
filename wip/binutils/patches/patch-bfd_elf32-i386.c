$NetBSD$

diff -urb bfd/elf32-i386.c.orig bfd/elf32-i386.c
--- bfd/elf32-i386.c.orig	Sun Apr 09 00:57:22 2006
+++ bfd/elf32-i386.c
@@ -3949,6 +3949,32 @@
 
 #include "elf32-target.h"
 
+/* MINIX support.  */
+
+#undef	TARGET_LITTLE_SYM
+#define	TARGET_LITTLE_SYM		bfd_elf32_i386_minix_vec
+#undef	TARGET_LITTLE_NAME
+#define	TARGET_LITTLE_NAME		"elf32-i386-minix"
+
+static void
+elf_i386_minix_post_process_headers (bfd *abfd,
+			       struct bfd_link_info *info ATTRIBUTE_UNUSED)
+{
+  Elf_Internal_Ehdr *i_ehdrp;
+
+  i_ehdrp = elf_elfheader (abfd);
+
+  /* Put an ABI label.  */
+  i_ehdrp->e_ident[EI_OSABI] = ELFOSABI_FREEBSD;
+}
+
+#undef	elf_backend_post_process_headers
+#define	elf_backend_post_process_headers	elf_i386_minix_post_process_headers
+#undef	elf32_bed
+#define	elf32_bed				elf32_i386_minix_bed
+
+#include "elf32-target.h"
+
 /* VxWorks support.  */
 
 #undef	TARGET_LITTLE_SYM
