$NetBSD$

--- soltools/inc/st_list.hxx.orig	2012-06-23 16:39:03.000000000 +0000
+++ soltools/inc/st_list.hxx
@@ -297,7 +297,7 @@ DynamicList<XY>::operator=( const Dynami
           it != i_rList.end();
           ++it )
     {
-     	push_back( new XY(*(*it)) );
+     	this->push_back( new XY(*(*it)) );
     }
     return *this;
 }
@@ -310,7 +310,7 @@ DynamicList<XY>::Insert(unsigned pos, XY
 	if ( pos > this->len )
 	  return;
 
-	checkSize(DynamicList<XY>::len+2);
+	this->checkSize(DynamicList<XY>::len+2);
 	memmove( DynamicList<XY>::inhalt+pos+1, DynamicList<XY>::inhalt+pos, (DynamicList<XY>::len-pos) * sizeof(XY*) );
 	this->inhalt[pos] = elem_;
 	this->len++;
