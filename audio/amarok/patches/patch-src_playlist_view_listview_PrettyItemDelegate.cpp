$NetBSD$

--- src/playlist/view/listview/PrettyItemDelegate.cpp.orig	2011-12-15 07:36:48.000000000 +0000
+++ src/playlist/view/listview/PrettyItemDelegate.cpp
@@ -460,7 +460,7 @@ void Playlist::PrettyItemDelegate::paint
                 else
                     ratingAlignment = Qt::AlignCenter;
 
-                Amarok::KRatingPainter::paintRating( painter, QRect( currentItemX, rowOffsetY, itemWidth, rowHeight ), ratingAlignment, rating, rating );
+                KRatingPainter::paintRating( painter, QRect( currentItemX, rowOffsetY, itemWidth, rowHeight ), ratingAlignment, rating, rating );
 
             }
             else if ( value == Divider )
