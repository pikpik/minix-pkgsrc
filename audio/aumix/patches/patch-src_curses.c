$NetBSD$

--- src/curses.c.orig	Mon Jun 26 22:51:42 2000
+++ src/curses.c	Tue Jul 11 10:01:13 2000
@@ -1,10 +1,10 @@
 /* curses.c:  functions specific to ncurses mode */
-#include "common.h"
+#include "./common.h"
 #ifdef HAVE_CURSES
 #include <ctype.h>		/* tolower() */
-#include "curses.h"
-#include "interactive.h"
-#include "mouse.h"
+#include "./curses.h"
+#include "./interactive.h"
+#include "./mouse.h"
 
 char           *chark, *charl, *charm, *charo, *charq, *chars, *charu, *lang;
 int             current_dev, level_increment, balance_increment, menu_width, level_width, label_width, balance_width, levelbalmode, cols_saved, lines_saved;
