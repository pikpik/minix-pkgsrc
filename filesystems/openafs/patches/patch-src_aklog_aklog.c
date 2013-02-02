$NetBSD$

--- src/aklog/aklog.c.orig	2012-03-26 23:03:34.000000000 +0000
+++ src/aklog/aklog.c
@@ -67,9 +67,11 @@
 #if defined(HAVE_ET_COM_ERR_H)
 #include <et/com_err.h>
 #else
-#include <com_err.h>
+//#include <com_err.h>
+#include <krb5/com_err.h>
 #endif
 
+
 #ifndef HAVE_KERBEROSV_HEIM_ERR_H
 #include <afs/com_err.h>
 #endif
@@ -95,6 +97,8 @@
 #include "aklog.h"
 #include "linked_list.h"
 
+#define HAVE_NO_KRB5_524
+
 #ifdef HAVE_KRB5_CREDS_KEYBLOCK
 #define USING_MIT 1
 #endif
