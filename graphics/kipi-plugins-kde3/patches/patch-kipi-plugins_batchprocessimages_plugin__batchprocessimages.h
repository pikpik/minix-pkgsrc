$NetBSD$

--- kipi-plugins/batchprocessimages/plugin_batchprocessimages.h.orig	2013-03-27 16:29:57.000000000 +0000
+++ kipi-plugins/batchprocessimages/plugin_batchprocessimages.h
@@ -33,15 +33,6 @@
 
 class KAction;
 
-class KIPIBatchProcessImagesPlugin::BorderImagesDialog;
-class KIPIBatchProcessImagesPlugin::ColorImagesDialog;
-class KIPIBatchProcessImagesPlugin::ConvertImagesDialog;
-class KIPIBatchProcessImagesPlugin::EffectImagesDialog;
-class KIPIBatchProcessImagesPlugin::FilterImagesDialog;
-class KIPIBatchProcessImagesPlugin::RenameImagesDialog;
-class KIPIBatchProcessImagesPlugin::RecompressImagesDialog;
-class KIPIBatchProcessImagesPlugin::ResizeImagesDialog;
-
 class Plugin_BatchProcessImages : public KIPI::Plugin
 {
 Q_OBJECT
