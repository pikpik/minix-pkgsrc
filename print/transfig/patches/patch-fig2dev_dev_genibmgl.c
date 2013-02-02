$NetBSD$

--- fig2dev/dev/genibmgl.c.orig	2012-04-27 18:39:11.000000000 +0000
+++ fig2dev/dev/genibmgl.c
@@ -567,7 +567,7 @@ double	length;
  * set_width - issue line width commands as appropriate
  *		NOTE: HPGL/2 command used
  */
-static set_width(w)
+static void set_width(w)
     int	w;
 {
     static int current_width=-1;
