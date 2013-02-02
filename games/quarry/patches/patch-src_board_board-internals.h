$NetBSD$

--- src/board/board-internals.h.orig	2012-11-15 15:11:27.000000000 +0000
+++ src/board/board-internals.h
@@ -89,7 +89,7 @@ struct _BoardChangeStackEntry {
 };
 
 
-inline void	board_undo_changes (Board *board, int num_undos);
+void	board_undo_changes (Board *board, int num_undos);
 
 int		determine_position_delta (int delta_x, int delta_y);
 
