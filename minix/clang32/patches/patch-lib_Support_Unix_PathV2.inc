$NetBSD$

--- lib/Support/Unix/PathV2.inc.orig	Thu Jun 28 00:55:40 2012
+++ lib/Support/Unix/PathV2.inc
@@ -531,6 +531,7 @@ error_code get_magic(const Twine &path, uint32_t len,
 
 error_code map_file_pages(const Twine &path, off_t file_offset, size_t size,  
                                             bool map_writable, void *&result) {
+#ifndef __minix
   SmallString<128> path_storage;
   StringRef name = path.toNullTerminatedStringRef(path_storage);
   int oflags = map_writable ? O_RDWR : O_RDONLY;
@@ -549,6 +550,9 @@ error_code map_file_pages(const Twine &path, off_t fil
   }
   
   return error_code::success();
+#else
+    return error_code(ENOSYS, system_category());
+#endif
 }
 
 error_code unmap_file_pages(void *base, size_t size) {
