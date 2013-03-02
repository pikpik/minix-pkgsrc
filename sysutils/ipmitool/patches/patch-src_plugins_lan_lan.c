$NetBSD$

--- src/plugins/lan/lan.c.orig	2013-03-01 13:05:13.000000000 +0000
+++ src/plugins/lan/lan.c
@@ -1071,7 +1071,7 @@ uint8_t * ipmi_lan_build_sol_msg(struct 
 	msg = malloc(len);
 	if (msg == NULL) {
 		lprintf(LOG_ERR, "ipmitool: malloc failure");
-		return;
+		return NULL;
 	}
 	memset(msg, 0, len);
 
