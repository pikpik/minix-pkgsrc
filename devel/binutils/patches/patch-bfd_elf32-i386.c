$NetBSD$

--- bfd/elf32-i386.c.orig	Mon Nov 21 09:29:15 2011
+++ bfd/elf32-i386.c
@@ -4971,6 +4971,11 @@ elf_i386_add_symbol_hook (bfd * abfd,
 #undef	ELF_OSABI
 #define	ELF_OSABI			ELFOSABI_FREEBSD
 
+#undef	TARGET_LITTLE_SYM
+#define	TARGET_LITTLE_SYM		bfd_elf32_i386_minix_vec
+#undef	TARGET_LITTLE_NAME
+#define	TARGET_LITTLE_NAME		"elf32-i386-minix"
+
 /* The kernel recognizes executables as valid only if they carry a
    "FreeBSD" label in the ELF header.  So we put this label on all
    executables and (for simplicity) also all other object files.  */
@@ -4990,6 +4995,11 @@ elf_i386_fbsd_post_process_headers (bfd *abfd, struct 
 #define	elf_backend_post_process_headers	elf_i386_fbsd_post_process_headers
 #undef	elf32_bed
 #define	elf32_bed				elf32_i386_fbsd_bed
+
+#undef	elf_backend_post_process_headers
+#define	elf_backend_post_process_headers	elf_i386_fbsd_post_process_headers
+#undef	elf32_bed
+#define	elf32_bed				elf32_i386_minix_bed
 
 #undef elf_backend_add_symbol_hook
 
