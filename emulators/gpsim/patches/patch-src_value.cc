$NetBSD$

Add missing include.

--- src/value.cc.orig	2005-09-10 13:45:30.000000000 +0000
+++ src/value.cc
@@ -22,6 +22,7 @@ Boston, MA 02111-1307, USA.  */
 #include <stdio.h>
 #include <iostream>
 #include <iomanip>
+#include <typeinfo>
 
 #include "processor.h"
 
