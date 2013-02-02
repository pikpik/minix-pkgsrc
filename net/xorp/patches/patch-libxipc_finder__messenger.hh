$NetBSD$

--- libxipc/finder_messenger.hh.orig	2009-01-05 18:30:55.000000000 +0000
+++ libxipc/finder_messenger.hh
@@ -141,7 +141,7 @@ private:
     };
     typedef map<uint32_t, ResponseState> SeqNoResponseMap;
 
-    friend class ResponseState;
+    friend struct ResponseState;
 
 private:
     EventLoop&				_eventloop;
