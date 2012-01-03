$NetBSD$

* Fix for http://www.ocert.org/advisories/ocert-2011-003.html
  from r321038 from PHP's repository.

--- main/php_globals.h.orig	2011-01-01 02:19:59.000000000 +0000
+++ main/php_globals.h
@@ -170,6 +170,8 @@ struct _php_core_globals {
 	char *mail_log;
 
 	zend_bool in_error_log;
+
+	long max_input_vars;
 };
 
 
