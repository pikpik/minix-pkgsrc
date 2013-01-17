$NetBSD$

--- src/websearch/websearchabstract.cpp.orig	2013-01-16 13:07:38.000000000 +0000
+++ src/websearch/websearchabstract.cpp
@@ -66,7 +66,7 @@ const int WebSearchAbstract::resultUnspe
 const char* WebSearchAbstract::httpUnsafeChars = "%:/=+$?&\0";
 
 
-HTTPEquivCookieJar::HTTPEquivCookieJar(QNetworkAccessManager *parent = NULL)
+HTTPEquivCookieJar::HTTPEquivCookieJar(QNetworkAccessManager *parent)
         : QNetworkCookieJar(parent), m_nam(parent)
 {
     // nothing
