$NetBSD$

--- fribidi_char_sets_cp1256.c.orig	2012-01-22 21:58:14.000000000 +0000
+++ fribidi_char_sets_cp1256.c
@@ -211,7 +211,7 @@ fribidi_unicode_to_cp1256_c (FriBidiChar
 	return (char) 0x99;
 
       default:
-	return '¿';
+	return (char) 0xbf;
       }
 }
 
