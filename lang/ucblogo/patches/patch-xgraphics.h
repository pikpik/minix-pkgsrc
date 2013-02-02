$NetBSD$

--- xgraphics.h.orig	2012-10-30 22:03:25.000000000 +0000
+++ xgraphics.h
@@ -30,6 +30,16 @@ void logofill(void);
 }
 
 #define prepare_to_draw          {checkX; placate_x();}
+
+#define checkX2(err) { \
+    if (have_x < 0) real_window_init(); \
+    if (!have_x) { \
+	err_logo(BAD_GRAPH_INIT,NIL); \
+	return (err); \
+    } \
+}
+
+#define prepare_to_draw2(err)          {checkX2(err); placate_x();}
 #define done_drawing             XFlush(dpy)
 extern void placate_x();
 
