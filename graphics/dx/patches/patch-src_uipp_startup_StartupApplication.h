$NetBSD$

--- src/uipp/startup/StartupApplication.h.orig	2003-09-20 05:33:56.000000000 +0000
+++ src/uipp/startup/StartupApplication.h
@@ -84,7 +84,7 @@ class StartupApplication : public IBMApp
     // Overrides the Application class version:
     //   Initializes Xt Intrinsics with option list (switches).
     //
-    virtual boolean initialize(unsigned int* argcp, char**argv);
+    virtual boolean initialize(int* argcp, char**argv);
 
     CommandScope       *commandScope;   // command scope
 
