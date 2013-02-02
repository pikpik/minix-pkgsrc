$NetBSD$

--- dlls/ntdll/nt.c.orig	2011-08-05 17:24:22.000000000 +0000
+++ dlls/ntdll/nt.c
@@ -1172,7 +1172,8 @@ void fill_cpu_info(void)
             fclose(f);
         }
     }
-#elif defined(__FreeBSD__) || defined (__FreeBSD_kernel__)
+#elif defined(__FreeBSD__) || defined (__FreeBSD_kernel__) \
+   || defined(__DragonFly__)
     {
         int ret, num;
         size_t len;
