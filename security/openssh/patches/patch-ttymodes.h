$NetBSD$

--- ttymodes.h.orig	Sun Mar 26 03:30:02 2006
+++ ttymodes.h
@@ -122,7 +122,9 @@ TTYMODE(ICRNL,	c_iflag, 36)
 TTYMODE(IUCLC,	c_iflag, 37)
 #endif
 TTYMODE(IXON,	c_iflag, 38)
+#if defined(IXANY)
 TTYMODE(IXANY,	c_iflag, 39)
+#endif
 TTYMODE(IXOFF,	c_iflag, 40)
 #ifdef IMAXBEL
 TTYMODE(IMAXBEL,c_iflag, 41)
