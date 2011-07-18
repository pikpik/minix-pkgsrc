$NetBSD$

--- tty.c.orig	Mon Jul 18 17:27:23 2011
+++ tty.c
@@ -35,8 +35,13 @@
 
 #include <term.h>
 
-static int	 charcost(char *);
+#ifdef __minix
+#include <termcap.h>
+#include <util.h>
+#endif
 
+static int	 charcost(const char *);
+
 static int	 cci;
 static int	 insdel;	/* Do we have both insert & delete line? */
 static char	*scroll_fwd;	/* How to scroll forward. */
@@ -66,10 +71,10 @@ ttinit(void)
 	signal(SIGCONT, winchhandler);
 	siginterrupt(SIGWINCH, 1);
 
-	scroll_fwd = scroll_forward;
+	scroll_fwd = (char *) scroll_forward;
 	if (scroll_fwd == NULL || *scroll_fwd == '\0') {
 		/* this is what GNU Emacs does */
-		scroll_fwd = parm_down_cursor;
+		scroll_fwd = (char *) parm_down_cursor;
 		if (scroll_fwd == NULL || *scroll_fwd == '\0')
 			scroll_fwd = "\n";
 	}
@@ -438,7 +443,7 @@ fakec(int c)
 
 /* calculate the cost of doing string s */
 static int
-charcost(char *s)
+charcost(const char *s)
 {
 	cci = 0;
 
