$NetBSD$

--- extern/solid/include/MT/Quaternion.h.orig	2012-07-03 13:16:43.000000000 +0000
+++ extern/solid/include/MT/Quaternion.h
@@ -158,7 +158,7 @@ namespace MT {
 
 		Quaternion<Scalar> inverse() const
 		{
-			return conjugate / length2();
+			return conjugate() / length2();
 		}
 		
 		Quaternion<Scalar> slerp(const Quaternion<Scalar>& q, const Scalar& t) const
