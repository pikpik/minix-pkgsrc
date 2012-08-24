$NetBSD$

--- libcpp/internal.h.orig	Mon Jan  9 08:48:43 2012
+++ libcpp/internal.h
@@ -726,7 +726,7 @@ extern cppchar_t _cpp_valid_ucn (cpp_reader *, const u
 extern void _cpp_destroy_iconv (cpp_reader *);
 extern unsigned char *_cpp_convert_input (cpp_reader *, const char *,
 					  unsigned char *, size_t, size_t,
-					  const unsigned char **, off_t *);
+					  const unsigned char **, big_off_t *);
 extern const char *_cpp_default_encoding (void);
 extern cpp_hashnode * _cpp_interpret_identifier (cpp_reader *pfile,
 						 const unsigned char *id,
