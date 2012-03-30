$NetBSD$

* Fix for CVE-2012-0259.

--- magick/property.c.orig	2012-03-01 01:41:19.000000000 +0000
+++ magick/property.c
@@ -1309,6 +1309,8 @@ static MagickBooleanType GetEXIFProperty
             buffer[MaxTextExtent],
             *value;
 
+	  value = NULL;
+	  *buffer = '\0';
           switch (format)
           {
             case EXIF_FMT_BYTE:
