$NetBSD$

--- XmgDict.c.orig	2013-01-16 11:25:14.000000000 +0000
+++ XmgDict.c
@@ -27,7 +27,7 @@ XFontStruct			*xfs;
 
   if (he = dict_get(XmgXFSDict,name))
     {
-      return ;
+      return 0;
     }
   else
     return (dict_add(XmgXFSDict,
@@ -71,7 +71,7 @@ Pixel				pixel;
 	{
 	  if (cmap == x->cmap)
 	    {
-	      return ;
+	      return 0;
 	    }
 	}
       VEC_ENDFOR;
@@ -158,7 +158,7 @@ Pixmap				pixmap;
 	{
 	  if (depth == x->depth)
 	    {
-	      return ;
+	      return 0;
 	    }
 	}
       VEC_ENDFOR;
