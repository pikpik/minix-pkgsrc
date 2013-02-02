$NetBSD: patch-apps_app__dial.c,v 1.2 2012/10/09 01:36:32 jnemeth Exp $

--- apps/app_dial.c.orig	2012-08-29 18:32:35.000000000 +0000
+++ apps/app_dial.c
@@ -2003,12 +2003,12 @@ static void end_bridge_callback(void *da
 
 	ast_channel_lock(chan);
 	if (ast_channel_cdr(chan)->answer.tv_sec) {
-		snprintf(buf, sizeof(buf), "%ld", (long) end - ast_channel_cdr(chan)->answer.tv_sec);
+		snprintf(buf, sizeof(buf), "%jd", (intmax_t) end - ast_channel_cdr(chan)->answer.tv_sec);
 		pbx_builtin_setvar_helper(chan, "ANSWEREDTIME", buf);
 	}
 
 	if (ast_channel_cdr(chan)->start.tv_sec) {
-		snprintf(buf, sizeof(buf), "%ld", (long) end - ast_channel_cdr(chan)->start.tv_sec);
+		snprintf(buf, sizeof(buf), "%jd", (intmax_t) end - ast_channel_cdr(chan)->start.tv_sec);
 		pbx_builtin_setvar_helper(chan, "DIALEDTIME", buf);
 	}
 	ast_channel_unlock(chan);
