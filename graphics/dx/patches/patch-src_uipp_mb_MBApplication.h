$NetBSD$

--- src/uipp/mb/MBApplication.h.orig	1999-05-10 15:46:25.000000000 +0000
+++ src/uipp/mb/MBApplication.h
@@ -51,8 +51,7 @@ class MBApplication : public IBMApplicat
     // Overrides the Application class version:
     //   Initializes Xt Intrinsics with option list (switches).
     //
-    virtual boolean initialize(unsigned int* argcp,
-			    char**        argv);
+    virtual boolean initialize(int* argcp, char** argv);
 
     static MBResource	resource;
 
