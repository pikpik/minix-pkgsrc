$NetBSD$

- use standard C

--- src/lib/sfio/Sfio_dc/sfdcsubstream.c.orig	1999-06-01 15:21:56.000000000 +0000
+++ src/lib/sfio/Sfio_dc/sfdcsubstream.c
@@ -133,9 +133,9 @@ Sfdisc_t*	disc;
 }
 
 #if __STD_C
-static streamexcept(Sfio_t* f, int type, Void_t* data, Sfdisc_t* disc)
+static int streamexcept(Sfio_t* f, int type, Void_t* data, Sfdisc_t* disc)
 #else
-static streamexcept(f, type, data, disc)
+static int streamexcept(f, type, data, disc)
 Sfio_t*		f;
 int		type;
 Void_t*		data;
