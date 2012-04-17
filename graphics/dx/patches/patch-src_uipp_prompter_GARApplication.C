$NetBSD$

--- src/uipp/prompter/GARApplication.C.orig	2006-05-08 16:20:13.000000000 +0000
+++ src/uipp/prompter/GARApplication.C
@@ -198,8 +198,7 @@ InitializeSignals(void)
     }
 }            
 
-boolean GARApplication::initialize(unsigned int* argcp,
-			       char**        argv)
+boolean GARApplication::initialize(int* argcp, char** argv)
 {
     ASSERT(argcp);
     ASSERT(argv);
