$NetBSD$

--- src/kiaxcontact.cpp.orig	2013-01-16 10:19:53.000000000 +0000
+++ src/kiaxcontact.cpp
@@ -21,7 +21,7 @@
 
 int KiaxContact::nextContact;
 
-KiaxContact::KiaxContact(QString cname="User", QString cnumber="12345678", QString caccountId="1") {
+KiaxContact::KiaxContact(QString cname, QString cnumber, QString caccountId) {
   id = QString::number(QDateTime::currentDateTime().toTime_t()) + QString::number(KiaxContact::nextContact);
   KiaxContact::nextContact++;
   name = cname;
