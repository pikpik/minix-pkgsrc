$NetBSD$

--- karm/karmstorage.h.orig	2013-03-26 10:10:20.000000000 +0000
+++ karm/karmstorage.h
@@ -41,7 +41,9 @@ class Preferences;
 class Task;
 class TaskView;
 class HistoryEvent;
-class KCal::Todo;
+namespace KCal {
+    class Todo;
+}
 
 /**
  * Singleton to store/retrieve KArm data to/from persistent storage.
