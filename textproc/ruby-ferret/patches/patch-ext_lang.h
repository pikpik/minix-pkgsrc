$NetBSD$

* Switch to modern Ruby's API: http://cvs.pld-linux.org/

--- ext/lang.h.orig	2011-06-10 06:23:08.000000000 +0000
+++ ext/lang.h
@@ -6,6 +6,10 @@
 #include <stdarg.h>
 #include <ruby.h>
 
+#ifndef RUBY_RUBY_H
+#define RUBY18
+#endif
+
 #undef close
 #undef rename
 #undef read
