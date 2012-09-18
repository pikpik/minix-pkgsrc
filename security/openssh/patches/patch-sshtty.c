$NetBSD$

--- sshtty.c.orig	Sat Jan  9 11:26:23 2010
+++ sshtty.c
@@ -77,7 +77,10 @@ enter_raw_mode(int quiet)
 	}
 	_saved_tio = tio;
 	tio.c_iflag |= IGNPAR;
-	tio.c_iflag &= ~(ISTRIP | INLCR | IGNCR | ICRNL | IXON | IXANY | IXOFF);
+	tio.c_iflag &= ~(ISTRIP | INLCR | IGNCR | ICRNL | IXON | IXOFF);
+#ifdef IXANY
+	tio.c_iflag &= ~IXANY;
+#endif
 #ifdef IUCLC
 	tio.c_iflag &= ~IUCLC;
 #endif
