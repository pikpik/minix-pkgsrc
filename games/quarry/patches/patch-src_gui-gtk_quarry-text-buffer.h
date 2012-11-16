$NetBSD$

--- src/gui-gtk/quarry-text-buffer.h.orig	2012-11-15 15:16:07.000000000 +0000
+++ src/gui-gtk/quarry-text-buffer.h
@@ -117,7 +117,7 @@ QuarryTextBufferUndoEntry *
 void		 quarry_text_buffer_undo_entry_delete
 		   (QuarryTextBufferUndoEntry *undo_entry);
 
-inline gboolean	 quarry_text_buffer_undo_entry_is_empty
+gboolean	 quarry_text_buffer_undo_entry_is_empty
 		   (const QuarryTextBufferUndoEntry *undo_entry);
 
 
