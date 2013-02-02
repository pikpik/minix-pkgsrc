$NetBSD$

--- morse.c.orig	2012-10-30 22:47:24.000000000 +0000
+++ morse.c
@@ -17,6 +17,7 @@ Foundation, Inc., 59 Temple Place - Suit
 
 */
 
+#include <ctype.h>
 #include <stdio.h>
 
 #include "cw.h"
