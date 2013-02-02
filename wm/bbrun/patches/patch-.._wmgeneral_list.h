$NetBSD$

--- ../wmgeneral/list.h.orig	2012-07-03 11:42:25.000000000 +0000
+++ ../wmgeneral/list.h
@@ -29,11 +29,7 @@ Boston, MA 02111-1307, USA.  */
 #ifndef __LIST_H_
 #define __LIST_H_
 
-#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
-# define INLINE inline
-#else
-# define INLINE
-#endif
+#define INLINE
 
 typedef struct LinkedList {
   void *head;
