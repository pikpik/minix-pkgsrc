$NetBSD$

--- src/lisp/getters.hpp.orig	2012-11-22 20:43:25.000000000 +0000
+++ src/lisp/getters.hpp
@@ -30,7 +30,7 @@ static inline bool property_get(const Li
   if(lisp->get_list_size() != 2)
     return false;
   
-  const Lisp* el = lisp->get_list_elem(1);
+  const Lisp* el = lisp->get_list_elem(1).get();
   return get(el, val);
 }
 
