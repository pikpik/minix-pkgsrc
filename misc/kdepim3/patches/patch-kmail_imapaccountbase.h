$NetBSD$

--- kmail/imapaccountbase.h.orig	2012-04-27 16:28:08.000000000 +0000
+++ kmail/imapaccountbase.h
@@ -32,7 +32,6 @@
 #include <qguardedptr.h>
 #include <kio/global.h>
 
-class AccountManager;
 class KMFolder;
 class KConfig/*Base*/;
 class KMMessagePart;
@@ -50,6 +49,7 @@ namespace KPIM {
 }
 
 namespace KMail {
+  class AccountManager;
   struct ACLListEntry;
   struct QuotaInfo;
   typedef QValueVector<KMail::ACLListEntry> ACLList;
