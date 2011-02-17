$NetBSD$

Fix build with gcc4.5

--- src/rsitimer.cpp.orig	2009-07-19 13:35:42.000000000 +0000
+++ src/rsitimer.cpp
@@ -490,7 +490,7 @@ void RSITimer::readConfig()
     m_ignoreIdleForTinyBreaks = config.readEntry( "IgnoreIdleForTinyBreaks", false );
 
     config = KGlobal::config()->group( "General" );
-    m_lastrunDt = config.readEntry( "LastRunTimeStamp", QDateTime::QDateTime() );
+    m_lastrunDt = config.readEntry( "LastRunTimeStamp", QDateTime() );
     m_lastrunTiny = config.readEntry( "LastRunTinyLeft", 0 );
     m_lastrunBig = config.readEntry( "LastRunBigLeft", 0 );
 }
