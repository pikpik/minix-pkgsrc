$NetBSD$

--- src/uipp/startup/StartupApplication.C.orig	2005-11-10 19:48:22.000000000 +0000
+++ src/uipp/startup/StartupApplication.C
@@ -117,8 +117,7 @@ InitializeSignals(void)
 #endif       
 }            
 
-boolean StartupApplication::initialize(unsigned int* argcp,
-			       char**        argv)
+boolean StartupApplication::initialize(int* argcp, char** argv)
 {
     ASSERT(argcp);
     ASSERT(argv);
