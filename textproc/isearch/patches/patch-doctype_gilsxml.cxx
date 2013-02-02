$NetBSD$

Chase after the C++ standard:
   - use the newfangled names for C++ headers

--- doctype/gilsxml.cxx~	2000-02-04 22:47:49.000000000 +0000
+++ doctype/gilsxml.cxx
@@ -43,11 +43,11 @@ Author:		Archie Warnock (awww@home.com),
 Originally by:  Kevin Gamiel, Kevin.Gamiel@cnidr.org
 @@@*/
 
-#include <iostream.h>
-#include <stdio.h>
-#include <stdlib.h>
-#include <string.h>
-#include <errno.h>
+#include <iostream>
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
+#include <cerrno>
 #include "isearch.hxx"
 #include "sgmltag.hxx"
 #include "gilsxml.hxx"
