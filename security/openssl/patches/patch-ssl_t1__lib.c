$NetBSD$

Fix for security issue CVE-2011-0014.

--- ssl/t1_lib.c.orig	Tue Nov 16 14:26:18 2010
+++ ssl/t1_lib.c
@@ -521,6 +521,7 @@ int ssl_parse_clienthello_tlsext(SSL *s, unsigned char
 						}
 					n2s(data, idsize);
 					dsize -= 2 + idsize;
+					size -= 2 + idsize;
 					if (dsize < 0)
 						{
 						*al = SSL_AD_DECODE_ERROR;
@@ -559,9 +560,14 @@ int ssl_parse_clienthello_tlsext(SSL *s, unsigned char
 					}
 
 				/* Read in request_extensions */
+				if (size < 2)
+					{
+					*al = SSL_AD_DECODE_ERROR;
+					return 0;
+					}
 				n2s(data,dsize);
 				size -= 2;
-				if (dsize > size) 
+				if (dsize != size) 
 					{
 					*al = SSL_AD_DECODE_ERROR;
 					return 0;
