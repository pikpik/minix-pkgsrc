$NetBSD$

--- libxipc/xrl_error.hh.orig	2009-01-05 18:30:56.000000000 +0000
+++ libxipc/xrl_error.hh
@@ -27,7 +27,7 @@
 #include "libxorp/c_format.hh"
 
 
-struct XrlErrlet;
+class XrlErrlet;
 
 enum XrlErrorCode {
     OKAY		  = 100,
