$NetBSD$

Fix "error: 'yield' was not declared in this scope"

--- Source/WebCore/platform/sql/SQLiteDatabase.cpp.orig	Wed Nov  7 07:59:38 2012
+++ Source/WebCore/platform/sql/SQLiteDatabase.cpp	Wed Nov  7 07:59:58 2012
@@ -125,7 +125,7 @@
         if (!m_db)
             return;
         sqlite3_interrupt(m_db);
-        yield();
+        WTF::yield();
     }
 
     m_lockingMutex.unlock();
