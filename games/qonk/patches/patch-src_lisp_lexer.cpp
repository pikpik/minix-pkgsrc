$NetBSD$

--- src/lisp/lexer.cpp.orig	2011-12-05 21:37:43.000000000 +0000
+++ src/lisp/lexer.cpp
@@ -19,6 +19,7 @@
 //  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 #include <sstream>
 #include <stdexcept>
+#include <cstring>
 
 #include "lexer.hpp"
 #include "translation.hpp"
