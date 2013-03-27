$NetBSD$

--- src/common/OW_SharedLibraryReference.hpp.orig	2013-03-25 15:05:11.000000000 +0000
+++ src/common/OW_SharedLibraryReference.hpp
@@ -113,7 +113,7 @@ public:
 	{
 		SharedLibraryReference<U> rval;
 		rval.m_sharedLib = m_sharedLib;
-		rval.m_obj = m_obj.cast_to<U>();
+		rval.m_obj = m_obj.template cast_to<U>();
 		return rval;
 	}
 
