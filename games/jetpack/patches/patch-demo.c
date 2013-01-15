$NetBSD$

--- demo.c.orig	2013-01-14 16:34:45.000000000 +0000
+++ demo.c
@@ -13,7 +13,7 @@ int	demostage, demodelay;
 	the demo, and demo_player does the actual player action. The level
 	itself is special level 0.
 */
-demo()
+void demo(void)
 {
 	register unsigned long	timer;
 
