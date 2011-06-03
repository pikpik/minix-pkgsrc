$NetBSD$

Fix build with png-1.5.

--- src/simage_png.c.orig	2002-08-21 09:15:15.000000000 +0000
+++ src/simage_png.c
@@ -323,7 +323,7 @@ simage_png_save(const char *filename,
   /* Set error handling.  REQUIRED if you aren't supplying your own
    * error hadnling functions in the png_create_write_struct() call.
    */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     /* If we get here, we had a problem reading the file */
     fclose(fp);
     png_destroy_write_struct(&png_ptr,  (png_infopp)info_ptr);
