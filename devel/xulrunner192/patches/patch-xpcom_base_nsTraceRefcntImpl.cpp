$NetBSD$

--- xpcom/base/nsTraceRefcntImpl.cpp.orig	2012-11-17 15:50:56.000000000 +0000
+++ xpcom/base/nsTraceRefcntImpl.cpp
@@ -1347,7 +1347,7 @@ nsTraceRefcntImpl::LogReleaseCOMPtr(void
   return NS_OK;
 }
 
-static const nsTraceRefcntImpl kTraceRefcntImpl;
+static nsTraceRefcntImpl kTraceRefcntImpl;
 
 NS_METHOD
 nsTraceRefcntImpl::Create(nsISupports* outer, const nsIID& aIID, void* *aInstancePtr)
