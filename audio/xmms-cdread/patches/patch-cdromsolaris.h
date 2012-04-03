$NetBSD$

--- cdromsolaris.h.orig	2001-08-18 12:05:55.000000000 +0200
+++ cdromsolaris.h	2012-01-02 19:18:35.520564824 +0100
@@ -30,7 +30,7 @@ trans_speed(int speed)
 |*|  Return -1 on error.
 \*/
 static int
-cdrom_open(const char *device, int &flags)
+cdrom_open(const char *device, int *flags)
 {
 	int fd;
 	int flg = *flags;
