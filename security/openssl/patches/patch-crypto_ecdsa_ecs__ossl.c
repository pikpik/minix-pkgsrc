$NetBSD$

Add protection against ECDSA timing attacks as mentioned in the paper
by Billy Bob Brumley and Nicola Tuveri, see:
  http://eprint.iacr.org/2011/232.pdf
[Billy Bob Brumley and Nicola Tuveri]

--- crypto/ecdsa/ecs_ossl.c.orig	Tue Dec  1 17:32:16 2009
+++ crypto/ecdsa/ecs_ossl.c
@@ -144,6 +144,16 @@ static int ecdsa_sign_setup(EC_KEY *eckey, BN_CTX *ctx
 			}
 		while (BN_is_zero(k));
 
+#ifdef ECDSA_POINT_MUL_NO_CONSTTIME
+		/* We do not want timing information to leak the length of k,
+		 * so we compute G*k using an equivalent scalar of fixed
+		 * bit-length. */
+
+		if (!BN_add(k, k, order)) goto err;
+		if (BN_num_bits(k) <= BN_num_bits(order))
+			if (!BN_add(k, k, order)) goto err;
+#endif /* def(ECDSA_POINT_MUL_NO_CONSTTIME) */
+
 		/* compute r the x-coordinate of generator * k */
 		if (!EC_POINT_mul(group, tmp_point, k, NULL, NULL, ctx))
 		{
