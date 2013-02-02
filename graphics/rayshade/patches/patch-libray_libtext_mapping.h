$NetBSD$

--- libray/libtext/mapping.h.orig	2012-12-25 18:59:13.000000000 +0000
+++ libray/libtext/mapping.h
@@ -36,5 +36,6 @@ typedef struct Mapping {
 
 extern Mapping *UVMappingCreate(), *SphereMappingCreate(), *CylMappingCreate(),
 	*LinearMappingCreate();
+void TextToUV(Mapping *mapping, Geom *prim, Vector *pos, Vector *norm, Float *u, Float *v, Vector *dpdu, Vector *dpdv);
 
 #endif /* MAPPING_H */
