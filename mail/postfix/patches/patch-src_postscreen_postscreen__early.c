$NetBSD$

--- src/postscreen/postscreen_early.c.orig	Sat Jan  8 21:37:28 2011
+++ src/postscreen/postscreen_early.c
@@ -162,8 +162,13 @@ static void psc_early_event(int event, char *context)
 	 * trickle in.
 	 */
     default:
+#ifndef MSG_PEEK
+    msg_info("%s: no MSG_PEEK, can't do it\n", myname);
+#else
 	if ((read_count = recv(vstream_fileno(state->smtp_client_stream),
-			  read_buf, sizeof(read_buf) - 1, MSG_PEEK)) <= 0) {
+			  read_buf, sizeof(read_buf) - 1, MSG_PEEK)) <= 0)
+#endif
+	{
 	    /* Avoid memory leak. */
 	    if (state->flags & PSC_STATE_FLAG_DNSBL_TODO)
 		(void) psc_dnsbl_retrieve(state->smtp_client_addr, &dnsbl_name,
