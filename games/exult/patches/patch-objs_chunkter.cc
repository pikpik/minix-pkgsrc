$NetBSD$

--- objs/chunkter.cc.orig	2011-11-25 17:56:42.000000000 +0000
+++ objs/chunkter.cc
@@ -30,6 +30,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #ifdef INCL_OPENGL
 #include "glshape.h"
 #endif
+#include <cstring>
 
 Chunk_terrain *Chunk_terrain::render_queue = 0;
 int Chunk_terrain::queue_size = 0;
