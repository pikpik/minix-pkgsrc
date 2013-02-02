$NetBSD$

Define EOF if needed.

--- ddd/strclass.C.orig	2009-02-11 17:25:06.000000000 +0000
+++ ddd/strclass.C
@@ -40,6 +40,10 @@ extern "C" int malloc_verify();
 #include <new>
 #include <stdlib.h>
 
+#ifndef EOF
+# define EOF (-1)
+#endif
+
 void string::error(const char* msg) const
 {
     std::cerr << "string: " << msg << "\n";
