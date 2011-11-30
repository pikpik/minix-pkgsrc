$NetBSD$

Conflicts with same definition in audiofile.h.

--- libaudiofile/af_vfs.h.orig	2011-09-13 03:59:06.000000000 +0000
+++ libaudiofile/af_vfs.h
@@ -34,8 +34,6 @@
 extern "C" {
 #endif
 
-typedef struct _AFvirtualfile AFvirtualfile;
-
 struct _AFvirtualfile
 {
 	ssize_t (*read) (AFvirtualfile *vfile, void *data, size_t nbytes);
