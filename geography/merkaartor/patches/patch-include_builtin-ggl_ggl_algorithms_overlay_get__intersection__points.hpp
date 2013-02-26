$NetBSD$

--- include/builtin-ggl/ggl/algorithms/overlay/get_intersection_points.hpp.orig	2011-02-10 12:00:35.000000000 +0000
+++ include/builtin-ggl/ggl/algorithms/overlay/get_intersection_points.hpp
@@ -94,8 +94,8 @@ struct relate
                     >
             >::relate(s1, s2);
 
-        ip_type& is = result.get<0>();
-        policies::relate::direction_type & dir = result.get<1>();
+        ip_type& is = get<0>(result);
+        policies::relate::direction_type & dir = get<1>(result);
 
         for (int i = 0; i < is.count; i++)
         {
