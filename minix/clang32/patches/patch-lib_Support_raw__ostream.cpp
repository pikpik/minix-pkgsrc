$NetBSD$

--- lib/Support/raw_ostream.cpp.orig	Thu Jun 28 00:55:41 2012
+++ lib/Support/raw_ostream.cpp
@@ -585,8 +585,8 @@ uint64_t raw_fd_ostream::seek(uint64_t off) {
 }
 
 size_t raw_fd_ostream::preferred_buffer_size() const {
-#if !defined(_MSC_VER) && !defined(__MINGW32__) && !defined(__minix)
-  // Windows and Minix have no st_blksize.
+#if !defined(_MSC_VER) && !defined(__MINGW32__)
+  // Windows has no st_blksize.
   assert(FD >= 0 && "File not yet open!");
   struct stat statbuf;
   if (fstat(FD, &statbuf) != 0)
