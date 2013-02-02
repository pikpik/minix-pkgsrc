$NetBSD$

--- src/3rdparty/clucene/src/CLucene/index/SegmentMerger.cpp.orig	2012-09-11 01:36:50.000000000 +0000
+++ src/3rdparty/clucene/src/CLucene/index/SegmentMerger.cpp
@@ -264,7 +264,7 @@ int32_t SegmentMerger::mergeFields()
     CND_CONDITION(fieldsWriter != NULL, "Memory allocation for fieldsWriter failed");
 
     try {  
-        IndexReader* reader = NULL;
+        reader = NULL;
         int32_t maxDoc          = 0;
         //Iterate through all readers
         for (uint32_t i = 0; i < readers.size(); i++) {
