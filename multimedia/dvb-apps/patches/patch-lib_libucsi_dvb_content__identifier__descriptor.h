$NetBSD$

--- lib/libucsi/dvb/content_identifier_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/content_identifier_descriptor.h
@@ -118,7 +118,7 @@ static inline struct dvb_content_identif
 		case 1:
 			if (len < (pos+2))
 				return NULL;
-			bswap16(buf+pos);
+			ubswap16(buf+pos);
 			break;
 		}
 	}
