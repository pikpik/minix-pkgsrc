--- gnu/wchar.in.h.orig	Sat Mar 12 09:14:34 2011
+++ gnu/wchar.in.h	Sat Jun  4 12:26:08 2011
--- gnu/wchar.in.h.orig	Sat Mar 12 09:14:34 2011
+++ gnu/wchar.in.h
@@ -33,7 +33,7 @@
 #endif
 @PRAGMA_COLUMNS@
 
-#if defined __need_mbstate_t || defined __need_wint_t || (defined __hpux && ((defined _INTTYPES_INCLUDED && !defined strtoimax) || defined _GL_JUST_INCLUDE_SYSTEM_WCHAR_H)) || defined _GL_ALREADY_INCLUDING_WCHAR_H
+#if defined __need_mbstate_t || defined __need_wint_t || (defined __hpux && ((defined _INTTYPES_INCLUDED && !defined strtoimax) || defined _GL_JUST_INCLUDE_SYSTEM_WCHAR_H)) || defined _GL_ALREADY_INCLUDING_WCHAR_H || defined _MINIX
 /* Special invocation convention:
    - Inside glibc and uClibc header files.
    - On HP-UX 11.00 we have a sequence of nested includes
