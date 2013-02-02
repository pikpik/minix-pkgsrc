$NetBSD$

--- src/dms/cdata.h.orig	2012-11-21 16:48:25.000000000 +0000
+++ src/dms/cdata.h
@@ -31,7 +31,7 @@
 		#define INLINE inline
 	#else
 		#ifdef __GNUC__
-			#define INLINE inline
+			#define INLINE static inline
 		#else
 			#ifdef __SASC
 				#define INLINE __inline
