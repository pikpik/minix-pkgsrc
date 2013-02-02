$NetBSD$

Add SONY Bravia support
http://blog-imgs-30.fc2.com/h/o/r/horip/mediatomb-0_12_1_bravia_support_0_1_patch.txt

--- src/transcoding/transcode_ext_handler.cc.orig	2010-03-25 14:58:07.000000000 +0000
+++ src/transcoding/transcode_ext_handler.cc
@@ -182,7 +182,7 @@ Ref<IOHandler> TranscodeExternalHandler:
 
             try
             {
-                chmod(location.c_str(), S_IWUSR | S_IRUSR);
+                chmod(location.c_str(), S_IWUSR | S_IRUSR | S_IROTH);
 
                 Ref<IOHandler> c_ioh(new CurlIOHandler(url, NULL, 
                    cfg->getIntOption(CFG_EXTERNAL_TRANSCODING_CURL_BUFFER_SIZE),
