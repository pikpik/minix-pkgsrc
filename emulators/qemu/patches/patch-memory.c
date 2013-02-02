$NetBSD: patch-memory.c,v 1.2 2012/09/11 17:13:45 asau Exp $

--- memory.c.orig	2012-12-03 19:37:05.000000000 +0000
+++ memory.c
@@ -313,7 +313,7 @@ static void memory_region_read_accessor(
     if (mr->flush_coalesced_mmio) {
         qemu_flush_coalesced_mmio_buffer();
     }
-    tmp = mr->ops->read(mr->opaque, addr, size);
+    tmp = (*mr->ops->read)(mr->opaque, addr, size);
     *value |= (tmp & mask) << shift;
 }
 
@@ -396,12 +396,12 @@ static void memory_region_iorange_read(I
 
         *data = ((uint64_t)1 << (width * 8)) - 1;
         if (mrp) {
-            *data = mrp->read(mr->opaque, offset);
+            *data = (*mrp->read)(mr->opaque, offset);
         } else if (width == 2) {
             mrp = find_portio(mr, offset - mrio->offset, 1, false);
             assert(mrp);
-            *data = mrp->read(mr->opaque, offset) |
-                    (mrp->read(mr->opaque, offset + 1) << 8);
+            *data = (*mrp->read)(mr->opaque, offset) |
+                    ((*mrp->read)(mr->opaque, offset + 1) << 8);
         }
         return;
     }
