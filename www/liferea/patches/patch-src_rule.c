$NetBSD$

--- src/rule.c.orig	2013-03-01 13:47:26.000000000 +0000
+++ src/rule.c
@@ -299,7 +299,7 @@ rules_check_item (GSList *rules, itemPtr
 	queryPtr	query;
 	
 	if (0 == g_slist_length (rules))
-		return;
+		return FALSE;
 	
 	/* first try in memory checks (for "unread" and "important" search folder)... */
 	if (1 == g_slist_length (rules)) {
