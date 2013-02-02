$NetBSD$
Fix build failure on Linux
--- linux/lmstemp.cc.orig	2006-02-18 05:13:07.000000000 +0000
+++ linux/lmstemp.cc
@@ -29,7 +29,7 @@ LmsTemp::LmsTemp( XOSView *parent, const
           << std::endl;
     	parent_->done(1);
     }
-    char *p;
+    const char *p;
     if ((p = strrchr(caption,'/')) != 0)
       _highest = atoi(p+1);
     else
