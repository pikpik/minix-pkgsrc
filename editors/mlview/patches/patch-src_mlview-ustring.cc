$NetBSD$

--- src/mlview-ustring.cc.orig	2011-11-24 02:25:01.000000000 +0000
+++ src/mlview-ustring.cc
@@ -59,7 +59,7 @@ UString::UString (const Glib::ustring &a
 UString::~UString ()
 {}
 
-UString::UString&
+UString&
 UString::operator= (const char *a_cstr)
 {
 	if (!a_cstr)
