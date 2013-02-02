$NetBSD$

--- common/putilimp.h.orig	2012-11-05 17:14:50.000000000 +0000
+++ common/putilimp.h
@@ -123,6 +123,8 @@ typedef size_t uintptr_t;
    /* not defined */
 #elif U_PLATFORM == U_PF_OS400
    /* not defined */
+#elif defined(__MirBSD__)
+   /* not defined */
 #else
 #   define U_TIMEZONE timezone
 #endif
