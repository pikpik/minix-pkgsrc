--- libcpp/internal.h.orig	Fri Aug 12 14:30:54 2011
+++ libcpp/internal.h	Fri Aug 12 14:31:14 2011
@@ -671,7 +671,7 @@
 extern void _cpp_destroy_iconv (cpp_reader *);
 extern unsigned char *_cpp_convert_input (cpp_reader *, const char *,
 					  unsigned char *, size_t, size_t,
-					  const unsigned char **, off_t *);
+					  const unsigned char **, big_off_t *);
 extern const char *_cpp_default_encoding (void);
 extern cpp_hashnode * _cpp_interpret_identifier (cpp_reader *pfile,
 						 const unsigned char *id,
