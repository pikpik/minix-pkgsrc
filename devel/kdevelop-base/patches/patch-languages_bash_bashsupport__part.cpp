$NetBSD$

--- languages/bash/bashsupport_part.cpp.orig	2011-11-25 19:18:23.000000000 +0000
+++ languages/bash/bashsupport_part.cpp
@@ -183,7 +183,7 @@ void BashSupportPart::startApplication(c
 {
 	kdDebug() << "starting application" << program << endl;
 	if (KDevAppFrontend *appFrontend = extension<KDevAppFrontend>("KDevelop/AppFrontend"))
-		appFrontend->startAppCommand(QString::QString(), program, TRUE);
+		appFrontend->startAppCommand(QString(), program, TRUE);
 }
 
 
