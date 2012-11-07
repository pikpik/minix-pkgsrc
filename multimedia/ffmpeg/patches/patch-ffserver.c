$NetBSD$

--- ffserver.c.orig	2012-11-06 23:43:44.000000000 +0000
+++ ffserver.c
@@ -3806,7 +3806,7 @@ static void add_codec(FFStream *stream, 
     AVStream *st;
 
     if(stream->nb_streams >= FF_ARRAY_ELEMS(stream->streams))
-        return NULL;
+        return;
 
     /* compute default parameters */
     switch(av->codec_type) {
