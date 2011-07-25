$NetBSD$

--- lib/libucsi/dvb/frequency_list_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/frequency_list_descriptor.h
@@ -69,7 +69,7 @@ static inline struct dvb_frequency_list_
 		return NULL;
 
 	while(pos < len) {
-		bswap32(buf+pos);
+		ubswap32(buf+pos);
 		pos += 4;
 	}
 
