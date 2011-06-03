$NetBSD$

--- src/lib/WPXStreamImplementation.cpp.orig	2011-02-04 19:44:52.000000000 +0000
+++ src/lib/WPXStreamImplementation.cpp
@@ -397,7 +397,7 @@ bool WPXStringStream::isOLEStream()
 WPXInputStream* WPXStringStream::getDocumentOLEStream(const char * name)
 {
 	if (!d->buffer.good())
-		return false;
+		return NULL;
 
 	Storage *tmpStorage = new Storage( d->buffer );
 	Stream tmpStream( tmpStorage, name );
