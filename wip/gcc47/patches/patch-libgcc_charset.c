--- libcpp/charset.c.orig	Fri Aug 12 14:32:30 2011
+++ libcpp/charset.c	Fri Aug 12 14:33:24 2011
@@ -1697,7 +1697,7 @@
 uchar * 
 _cpp_convert_input (cpp_reader *pfile, const char *input_charset,
 		    uchar *input, size_t size, size_t len,
-		    const unsigned char **buffer_start, off_t *st_size)
+		    const unsigned char **buffer_start, big_off_t *st_size)
 {
   struct cset_converter input_cset;
   struct _cpp_strbuf to;
