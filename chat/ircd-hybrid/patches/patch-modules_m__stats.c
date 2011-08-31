$NetBSD$

--- modules/m_stats.c.orig	Wed Feb 28 04:17:53 2007
+++ modules/m_stats.c
@@ -318,7 +318,7 @@ mo_stats(struct Client *client_p, struct Client *sourc
 static void
 send_usage(struct Client *source_p)
 {
-#ifndef _WIN32
+#if defined(_WIN32) || defined(__minix3)
   struct rusage rus;
   time_t secs;
   time_t rup;
