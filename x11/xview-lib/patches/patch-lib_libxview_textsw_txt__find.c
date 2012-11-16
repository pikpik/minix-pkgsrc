$NetBSD$

--- lib/libxview/textsw/txt_find.c.orig	2012-11-14 15:43:10.000000000 +0000
+++ lib/libxview/textsw/txt_find.c
@@ -142,7 +142,7 @@ textsw_find_selection_and_normalize(view
 }
 
 /* Caller must set *first to be position at which to start the search. */
-Pkg_private int
+Pkg_private void
 textsw_find_pattern(textsw, first, last_plus_one, buf, buf_len, flags)
     Textsw_folio    textsw;
     Es_index       *first, *last_plus_one;
