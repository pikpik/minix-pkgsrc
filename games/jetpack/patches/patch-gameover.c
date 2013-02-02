$NetBSD$

--- gameover.c.orig	2013-01-14 16:36:44.000000000 +0000
+++ gameover.c
@@ -8,7 +8,7 @@ int	dead, deadtimer;
 
 /*	death is called when a player is killed.
 */
-death()
+void death(void)
 {
     men--;
     if(men < 0) {
