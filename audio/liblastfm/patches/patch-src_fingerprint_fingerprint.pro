$NetBSD$

--- src/fingerprint/fingerprint.pro.orig	2013-03-23 15:17:33.000000000 +0000
+++ src/fingerprint/fingerprint.pro
@@ -1,6 +1,6 @@
 TEMPLATE = lib
 TARGET = lastfm_fingerprint
-LIBS += -L$$DESTDIR -llastfm
+LIBS += ../../_bin/liblastfm.la
 QT = core xml network sql
 include( _files.qmake )
 DEFINES += LASTFM_OHAI_QMAKE
