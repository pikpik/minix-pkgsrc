$NetBSD$

Include <cstdio> for the EOF macro.

--- sim/ucsim/cmd.src/cmdlex.l.orig	2004-07-16 16:32:30.000000000 +0000
+++ sim/ucsim/cmd.src/cmdlex.l
@@ -1,6 +1,7 @@
 %{
 #include "cmdlexcl.h"
 #include "cmdpars.h"
+#include <cstdio>
 
 static YY_cl_ucsim_parser_STYPE *yylval;
 
