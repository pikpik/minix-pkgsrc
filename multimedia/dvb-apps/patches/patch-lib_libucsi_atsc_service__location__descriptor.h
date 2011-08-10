$NetBSD$

--- lib/libucsi/atsc/service_location_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/atsc/service_location_descriptor.h
@@ -75,14 +75,14 @@ static inline struct atsc_service_locati
 
 	if (d->len < 3)
 		return NULL;
-	bswap16(buf + pos);
+	ubswap16(buf + pos);
 	pos+=3;
 
 	for(idx = 0; idx < ret->number_elements; idx++) {
 		if (d->len < (pos + sizeof(struct atsc_caption_service_entry)))
 			return NULL;
 
-		bswap16(buf+pos+1);
+		ubswap16(buf+pos+1);
 
 		pos += sizeof(struct atsc_caption_service_entry);
 	}
