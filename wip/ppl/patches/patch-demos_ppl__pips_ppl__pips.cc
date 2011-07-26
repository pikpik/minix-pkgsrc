$NetBSD$

--- demos/ppl_pips/ppl_pips.cc.orig	Tue Jul 26 11:58:53 2011
+++ demos/ppl_pips/ppl_pips.cc
@@ -616,7 +616,8 @@ warning(const char* format, ...) {
   va_end(ap);
 }
 
-#if PPL_HAVE_DECL_RLIMIT_AS
+#if PPL_HAVE_DECL_RLIMIT_AS \
+  && HAVE_DECL_SETRLIMIT == 1
 
 void
 limit_virtual_memory(const unsigned long bytes) {
