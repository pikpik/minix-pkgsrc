$NetBSD$

--- plug-ins/bracketing_to_hdr/br_core/ResponseSolver.hpp.orig	2011-11-23 16:54:11.000000000 +0000
+++ plug-ins/bracketing_to_hdr/br_core/ResponseSolver.hpp
@@ -44,7 +44,7 @@
 #include "Exception.hpp"        // IF_FAIL_EXCEPTION()
 #include "br_macros.hpp"
 #include "ResponseSolverBase.hpp"
-
+#include <cstring>
 
 namespace br {
 
