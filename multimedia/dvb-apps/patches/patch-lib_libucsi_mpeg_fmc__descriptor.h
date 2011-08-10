$NetBSD$

--- lib/libucsi/mpeg/fmc_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/mpeg/fmc_descriptor.h
@@ -64,7 +64,7 @@ static inline struct mpeg_fmc_descriptor
 		return NULL;
 
 	while(pos < len) {
-		bswap16(buf+pos);
+		ubswap16(buf+pos);
 		pos += sizeof(struct mpeg_flex_mux);
 	}
 
