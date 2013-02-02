$NetBSD$

--- main.cpp.orig	2012-07-04 13:28:11.000000000 +0000
+++ main.cpp
@@ -251,7 +251,7 @@ int main(int argc, char* argv[])
             vymBaseDir.setPath(basePath + "/share/vym");
 
 	#else
-	    vymBaseDir.setPath ("/usr/share/vym");
+	    vymBaseDir.setPath ("@PREFIX@/share/vym");
 	    if (!vymBaseDir.exists())
 	    {
 		vymBaseDir.setPath ("/usr/local/share/vym");
