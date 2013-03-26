$NetBSD$

--- lib/Support/raw_ostream.cpp.orig	Wed Aug 29 22:57:00 2012
+++ lib/Support/raw_ostream.cpp
@@ -586,8 +586,8 @@ uint64_t raw_fd_ostream::seek(uint64_t off) {
 }
 
 size_t raw_fd_ostream::preferred_buffer_size() const {
-#if !defined(_MSC_VER) && !defined(__MINGW32__) && !defined(__minix)
-  // Windows and Minix have no st_blksize.
+#if !defined(_MSC_VER) && !defined(__MINGW32__)
+  // Windows has no st_blksize.
   assert(FD >= 0 && "File not yet open!");
   struct stat statbuf;
   if (fstat(FD, &statbuf) != 0)
