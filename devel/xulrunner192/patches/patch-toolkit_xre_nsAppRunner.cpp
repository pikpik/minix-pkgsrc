$NetBSD$

--- toolkit/xre/nsAppRunner.cpp.orig	2012-11-17 18:29:03.000000000 +0000
+++ toolkit/xre/nsAppRunner.cpp
@@ -987,7 +987,7 @@ nsXULAppInfo::SetSubmitReports(PRBool aE
 
 #endif
 
-static const nsXULAppInfo kAppInfo;
+static nsXULAppInfo kAppInfo;
 static NS_METHOD AppInfoConstructor(nsISupports* aOuter,
                                     REFNSIID aIID, void **aResult)
 {
