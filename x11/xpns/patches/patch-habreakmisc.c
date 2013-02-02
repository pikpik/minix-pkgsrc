$NetBSD$

--- habreakmisc.c.orig	2012-08-10 13:29:10.000000000 +0000
+++ habreakmisc.c
@@ -52,7 +52,7 @@ void HaBreakInit()
 ** RETURN: 	
 ** ANMERK: 	
 *************************************************************************/
-static HaBreakMark( MarkOn)
+static void HaBreakMark( MarkOn)
   BOOLEAN 	MarkOn;
 {
   OBJECT	*e;
