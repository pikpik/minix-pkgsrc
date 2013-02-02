$NetBSD$

--- cut-paste.c.orig	2013-01-10 22:43:42.000000000 +0000
+++ cut-paste.c
@@ -312,7 +312,7 @@ int len;
 			default:	break;
 		}
 	}
-	return;	/* Hopefully, we never reach here */
+	return NULL;	/* Hopefully, we never reach here */
 }
 
 
