$NetBSD$

--- src/single.c.orig	2012-07-03 13:14:23.000000000 +0000
+++ src/single.c
@@ -476,7 +476,7 @@ ai_invertdir (int dir)
 };
 
 
-inline int
+static inline int
 ai_checknewpos (_point pos, int d)
 {
     _point m;
