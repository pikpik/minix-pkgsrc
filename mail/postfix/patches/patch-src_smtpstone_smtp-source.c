$NetBSD$

--- src/smtpstone/smtp-source.c.orig	Sun Sep  5 16:44:13 2010
+++ src/smtpstone/smtp-source.c
@@ -446,7 +446,6 @@ static void fail_connect(SESSION *session)
 static void start_connect(SESSION *session)
 {
     int     fd;
-    struct linger linger;
 
     /*
      * Some systems don't set the socket error when connect() fails early
@@ -457,12 +456,19 @@ static void start_connect(SESSION *session)
     if ((fd = socket(sa->sa_family, SOCK_STREAM, 0)) < 0)
 	msg_fatal("socket: %m");
     (void) non_blocking(fd, NON_BLOCKING);
+#ifdef SO_LINGER
+  {
+    struct linger linger;
     linger.l_onoff = 1;
     linger.l_linger = 0;
     if (setsockopt(fd, SOL_SOCKET, SO_LINGER, (char *) &linger,
 		   sizeof(linger)) < 0)
 	msg_warn("setsockopt SO_LINGER %d: %m", linger.l_linger);
     session->stream = vstream_fdopen(fd, O_RDWR);
+ }
+#else
+	msg_warn("setsockopt SO_LINGER not found defined");
+#endif
     event_enable_write(fd, connect_done, (char *) session);
     smtp_timeout_setup(session->stream, var_timeout);
     if (inet_windowsize > 0)
