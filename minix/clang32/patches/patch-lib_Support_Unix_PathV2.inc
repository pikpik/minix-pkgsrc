$NetBSD$

--- lib/Support/Unix/PathV2.inc.orig	Wed Aug 15 19:16:27 2012
+++ lib/Support/Unix/PathV2.inc
@@ -482,7 +482,11 @@ error_code mapped_file_region::init(int fd, uint64_t o
       return error_code(errno, system_category());
   }
 
+#ifndef __minix
   int flags = (Mode == readwrite) ? MAP_SHARED : MAP_PRIVATE;
+#else
+  int flags = MAP_PRIVATE;
+#endif
   int prot = (Mode == readonly) ? PROT_READ : (PROT_READ | PROT_WRITE);
 #ifdef MAP_FILE
   flags |= MAP_FILE;
@@ -649,6 +653,7 @@ error_code get_magic(const Twine &path, uint32_t len,
 
 error_code map_file_pages(const Twine &path, off_t file_offset, size_t size,  
                                             bool map_writable, void *&result) {
+#ifndef __minix
   SmallString<128> path_storage;
   StringRef name = path.toNullTerminatedStringRef(path_storage);
   int oflags = map_writable ? O_RDWR : O_RDONLY;
@@ -667,6 +672,9 @@ error_code map_file_pages(const Twine &path, off_t fil
   }
   
   return error_code::success();
+#else
+    return error_code(ENOSYS, system_category());
+#endif
 }
 
 error_code unmap_file_pages(void *base, size_t size) {
