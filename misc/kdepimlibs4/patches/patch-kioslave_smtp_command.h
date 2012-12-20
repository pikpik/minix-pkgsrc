$NetBSD$

--- kioslave/smtp/command.h.orig	2011-07-27 18:34:56.000000000 +0000
+++ kioslave/smtp/command.h
@@ -32,6 +32,7 @@
 #ifndef __KIOSMTP_COMMAND_H__
 #define __KIOSMTP_COMMAND_H__
 
+#include <sys/types.h>
 
 extern "C" {
 #include <sasl/sasl.h>
