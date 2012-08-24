$NetBSD$

--- libcpp/charset.c.orig	Mon Jan  3 20:52:22 2011
+++ libcpp/charset.c
@@ -1697,7 +1697,7 @@ _cpp_interpret_identifier (cpp_reader *pfile, const uc
 uchar * 
 _cpp_convert_input (cpp_reader *pfile, const char *input_charset,
 		    uchar *input, size_t size, size_t len,
-		    const unsigned char **buffer_start, off_t *st_size)
+		    const unsigned char **buffer_start, big_off_t *st_size)
 {
   struct cset_converter input_cset;
   struct _cpp_strbuf to;
