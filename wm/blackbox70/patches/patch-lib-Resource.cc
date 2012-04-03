$NetBSD$

--- lib/Resource.cc.orig	2011-11-22 18:36:20.000000000 +0000
+++ lib/Resource.cc
@@ -29,6 +29,7 @@
 #include <X11/Xresource.h>
 
 #include <stdio.h>
+#include <strings.h>
 
 
 bt::Resource::Resource(void)
