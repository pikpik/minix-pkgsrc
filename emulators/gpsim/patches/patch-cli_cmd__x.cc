$NetBSD$

Add missing include.

--- cli/cmd_x.cc.orig	2005-05-11 13:29:02.000000000 +0000
+++ cli/cmd_x.cc
@@ -22,6 +22,7 @@ Boston, MA 02111-1307, USA.  */
 #include <iostream>
 #include <iomanip>
 #include <string>
+#include <typeinfo>
 
 
 #include "command.h"
