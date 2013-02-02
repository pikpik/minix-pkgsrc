$NetBSD$

--- src/sgf/sgf-privates.h.orig	2012-11-15 15:23:14.000000000 +0000
+++ src/sgf/sgf-privates.h
@@ -79,7 +79,7 @@ void		sgf_property_free_value (SgfValueT
 					 SgfValue *value);
 
 /* Defined in `sgf-utils.c', but also used from `sgf-undo.c'. */
-inline void	sgf_utils_do_switch_to_given_node (SgfGameTree *tree,
+void	sgf_utils_do_switch_to_given_node (SgfGameTree *tree,
 						   SgfNode *node);
 void		sgf_utils_descend_nodes (SgfGameTree *tree, int num_nodes);
 void		sgf_utils_ascend_nodes (SgfGameTree *tree, int num_nodes);
