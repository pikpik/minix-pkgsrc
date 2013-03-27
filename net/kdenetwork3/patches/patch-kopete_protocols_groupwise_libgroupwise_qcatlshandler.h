$NetBSD$

--- kopete/protocols/groupwise/libgroupwise/qcatlshandler.h.orig	2013-03-26 19:57:51.000000000 +0000
+++ kopete/protocols/groupwise/libgroupwise/qcatlshandler.h
@@ -23,7 +23,9 @@
 //#include <qtimer.h>
 #include "tlshandler.h"
 
-class QCA::TLS;
+namespace QCA {
+class TLS;
+}
 
 class QCATLSHandler : public TLSHandler
 {
