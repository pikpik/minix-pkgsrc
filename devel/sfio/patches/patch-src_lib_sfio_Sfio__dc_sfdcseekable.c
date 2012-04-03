$NetBSD$

- use standard C

--- src/lib/sfio/Sfio_dc/sfdcseekable.c.orig	1998-03-19 16:11:36.000000000 +0000
+++ src/lib/sfio/Sfio_dc/sfdcseekable.c
@@ -126,9 +126,9 @@ Sfdisc_t*	disc;
 
 /* on close, remove the discipline */
 #if __STD_C
-static skexcept(Sfio_t* f, int type, Void_t* data, Sfdisc_t* disc)
+static int skexcept(Sfio_t* f, int type, Void_t* data, Sfdisc_t* disc)
 #else
-static skexcept(f,type,data,disc)
+static int skexcept(f,type,data,disc)
 Sfio_t*		f;
 int		type;
 Void_t*		data;
