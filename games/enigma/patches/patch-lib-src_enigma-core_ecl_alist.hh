$NetBSD$

Fix C++ error.

--- lib-src/enigma-core/ecl_alist.hh.orig	2011-02-22 13:22:18.000000000 +0000
+++ lib-src/enigma-core/ecl_alist.hh
@@ -61,7 +61,7 @@ namespace ecl
 	VAL &operator[] (const key_type &key) { 
             iterator i=find(key);
             if (i==this->end())
-                i=insert(this->end(), make_pair(key, VAL()));
+                i=this->insert(this->end(), make_pair(key, VAL()));
             return i->second;
         }
     };
