$NetBSD$

--- tar/write.c.orig	Mon Feb  7 23:59:46 2011
+++ tar/write.c
@@ -843,7 +843,7 @@ write_hierarchy(struct bsdtar *bsdtar, struct archive 
 		 * If this file/dir is flagged "nodump" and we're
 		 * honoring such flags, skip this file/dir.
 		 */
-#ifdef HAVE_STRUCT_STAT_ST_FLAGS
+#if defined(HAVE_STRUCT_STAT_ST_FLAGS) && defined(UF_NODUMP)
 		/* BSD systems store flags in struct stat */
 		if (bsdtar->option_honor_nodump &&
 		    (lst->st_flags & UF_NODUMP))
