$NetBSD$

ensure varargs prototypes to fix build on 64bit

--- source/3rdparty/sge_depend/def.h.orig	2012-04-10 04:36:21.000000000 +0000
+++ source/3rdparty/sge_depend/def.h
@@ -170,6 +170,8 @@ int cppsetup();
 struct symtab **isdefined();
 #endif
 
+#define NeedVarargsPrototypes 1
+
 #if NeedVarargsPrototypes
 extern void fatalerr(char *, ...);
 extern void warning(char *, ...);
