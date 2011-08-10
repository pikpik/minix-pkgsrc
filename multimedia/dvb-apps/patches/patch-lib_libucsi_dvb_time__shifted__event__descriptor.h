$NetBSD$

--- lib/libucsi/dvb/time_shifted_event_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/time_shifted_event_descriptor.h
@@ -52,8 +52,8 @@ static inline struct dvb_time_shifted_ev
 	if (d->len != (sizeof(struct dvb_time_shifted_event_descriptor) - 2))
 		return NULL;
 
-	bswap16((uint8_t*) d + 2);
-	bswap16((uint8_t*) d + 4);
+	ubswap16((uint8_t*) d + 2);
+	ubswap16((uint8_t*) d + 4);
 
 	return (struct dvb_time_shifted_event_descriptor*) d;
 }
