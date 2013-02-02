$NetBSD$

--- src/fasthenry/mulDo.c.orig	2012-12-25 16:15:21.000000000 +0000
+++ src/fasthenry/mulDo.c
@@ -151,8 +151,7 @@ int type;
 /* 
 Loop through upward pass. 
 */
-mulUp(sys)
-ssystem *sys;
+void mulUp(ssystem *sys)
 {
 int i, j, k, l;
 int msize;
@@ -233,8 +232,7 @@ ssystem *sys;
 /* 
 Loop through downward pass. 
 */
-mulDown(sys)
-ssystem *sys;
+void mulDown(ssystem *sys)
 {
   cube *nc;
   int depth, i, j, k, lsize;
