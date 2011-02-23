$NetBSD$

Fix C++ error.

--- lib-src/enigma-core/ecl_dict.hh.orig	2011-02-22 13:20:39.000000000 +0000
+++ lib-src/enigma-core/ecl_dict.hh
@@ -27,6 +27,7 @@ namespace ecl
     extern unsigned hash(const std::string &key);
 
     class XInvalidKey : XGeneric {
+    public:
 	XInvalidKey () : XGeneric("invalid dictionary key")
         {}
     };
