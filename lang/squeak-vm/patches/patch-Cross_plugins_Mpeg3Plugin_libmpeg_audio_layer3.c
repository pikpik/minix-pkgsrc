$NetBSD$

--- Cross/plugins/Mpeg3Plugin/libmpeg/audio/layer3.c.orig	2012-10-20 13:51:52.000000000 +0000
+++ Cross/plugins/Mpeg3Plugin/libmpeg/audio/layer3.c
@@ -884,7 +884,7 @@ int mpeg3audio_III_antialias(mpeg3audio_
 	if(gr_info->block_type == 2) 
 	{
     	if(!gr_info->mixed_block_flag) 
-        	return;
+        	return 0;
     	sblim = 1; 
 	}
 	else 
