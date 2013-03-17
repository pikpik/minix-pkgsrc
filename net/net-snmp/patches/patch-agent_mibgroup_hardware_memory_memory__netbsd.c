$NetBSD$

--- agent/mibgroup/hardware/memory/memory_netbsd.c.orig	2012-10-09 22:28:58.000000000 +0000
+++ agent/mibgroup/hardware/memory/memory_netbsd.c
@@ -174,7 +174,7 @@ int netsnmp_mem_arch_load( netsnmp_cache
              mem->descr = strdup("Memory buffers");
         mem->units = 1024;
         mem->size  =  maxbufspace            /1024;
-        mem->size  = (maxbufspace - bufspace)/1024;
+        mem->free  = (maxbufspace - bufspace)/1024;
     }
 #endif
 
