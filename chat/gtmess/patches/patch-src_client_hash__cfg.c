$NetBSD$

--- src/client/hash_cfg.c.orig	2012-11-15 13:33:33.000000000 +0000
+++ src/client/hash_cfg.c
@@ -117,9 +117,6 @@ hash (register const char *str, register
   return hval;
 }
 
-#ifdef __GNUC__
-__inline
-#endif
 struct hct_entry *
 in_word_set (register const char *str, register unsigned int len)
 {
