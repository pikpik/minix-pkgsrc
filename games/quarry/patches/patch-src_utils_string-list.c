$NetBSD$

--- src/utils/string-list.c.orig	2012-11-15 15:09:31.000000000 +0000
+++ src/utils/string-list.c
@@ -689,7 +689,7 @@ association_list_item_dispose (Associati
 }
 
 
-inline char *
+char *
 association_list_find_association (AssociationList *list, const char *key)
 {
   AssociationListItem *item = association_list_find (list, key);
