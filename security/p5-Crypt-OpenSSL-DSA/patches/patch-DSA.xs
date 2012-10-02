$NetBSD$

Croak in do_verify() if the openssl library returns an error,
similar to what is already done in verify().

--- DSA.xs.orig	2005-05-22 20:14:52.000000000 +0000
+++ DSA.xs
@@ -139,6 +139,8 @@ do_verify(dsa, dgst, sig)
     CODE:
         dgst_pv = SvPV(dgst, dgst_len);
         RETVAL = DSA_do_verify(dgst_pv, dgst_len, sig, dsa);
+	if (RETVAL == -1)
+	  croak("Error in DSA_do_verify: %s",ERR_error_string(ERR_get_error(), NULL));
     OUTPUT:
         RETVAL
 
