$NetBSD$

--- lib/libucsi/mpeg/pat_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/mpeg/pat_section.c
@@ -34,8 +34,8 @@ struct mpeg_pat_section *mpeg_pat_sectio
 		if ((pos + 4) > len)
 			return NULL;
 
-		bswap16(buf + pos);
-		bswap16(buf + pos + 2);
+		ubswap16(buf + pos);
+		ubswap16(buf + pos + 2);
 		pos += 4;
 	}
 
