$NetBSD$

Include unistd.h for read() and close()

--- libs/filesystem/src/unique_path.cpp.orig	Thu Aug  2 12:04:47 2012
+++ libs/filesystem/src/unique_path.cpp	Thu Aug  2 12:04:55 2012
@@ -21,6 +21,7 @@
 
 # ifdef BOOST_POSIX_API
 #   include <fcntl.h>
+#   include <unistd.h>
 # else // BOOST_WINDOWS_API
 #   include <windows.h>
 #   include <wincrypt.h>
