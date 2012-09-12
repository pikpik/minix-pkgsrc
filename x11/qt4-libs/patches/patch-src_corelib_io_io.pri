$NetBSD$

Use kqueue instead of fam to monitor the file system
--- src/corelib/io/io.pri.orig	2012-04-26 19:46:08.000000000 +0000
+++ src/corelib/io/io.pri
@@ -103,7 +103,7 @@ win32 {
         }
 
         !nacl {
-            freebsd-*|macx-*|darwin-*|openbsd-*:{
+            freebsd-*|macx-*|darwin-*|openbsd-*|netbsd-*:{
                 SOURCES += io/qfilesystemwatcher_kqueue.cpp
                 HEADERS += io/qfilesystemwatcher_kqueue_p.h
             }
