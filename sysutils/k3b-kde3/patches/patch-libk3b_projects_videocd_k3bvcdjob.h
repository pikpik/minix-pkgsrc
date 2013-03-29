$NetBSD$

--- libk3b/projects/videocd/k3bvcdjob.h.orig	2013-03-27 21:14:00.000000000 +0000
+++ libk3b/projects/videocd/k3bvcdjob.h
@@ -25,8 +25,6 @@ class K3bProcess;
 class KProcess;
 class QDataStream;
 class K3bAbstractWriter;
-class K3bDevice::Device;
-
 
 class K3bVcdJob : public K3bBurnJob
 {
