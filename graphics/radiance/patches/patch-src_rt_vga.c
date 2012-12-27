$NetBSD$

Pass around input buffer lengths.

--- src/rt/vga.c~	2004-04-10 02:54:10.000000000 +0000
+++ src/rt/vga.c
@@ -187,6 +187,7 @@ vga_errout(
 static void
 vga_comin(			/* get input line from console */
 	char  *buf,
+	size_t max,
 	char  *prompt
 )
 {
@@ -194,7 +195,7 @@ vga_comin(			/* get input line from cons
 
 	if (prompt != NULL)
 		_outtext(prompt);
-	editline(buf, getch, vga_comout);
+	editline(buf, max, getch, vga_comout);
 	vga_driver.inpready = kbhit();
 }
 
