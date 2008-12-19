$NetBSD: patch-ntlmssp.inc.c,v 1.1.1.1 2008/10/17 19:23:25 sborrill Exp $
--- ntlmssp.inc.c.orig	2004-02-19 15:24:08.000000000 +0000
+++ ntlmssp.inc.c	2008-10-17 17:53:34.000000000 +0100
@@ -1,1 +1,2 @@
+#include "httpd/httpd.h"
 /*
