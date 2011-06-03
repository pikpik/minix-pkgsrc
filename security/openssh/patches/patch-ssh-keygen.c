--- ssh-keygen.c.orig	Fri Jun  3 13:08:10 2011
+++ ssh-keygen.c	Fri Jun  3 13:10:15 2011
@@ -1381,6 +1381,7 @@
 static void
 do_ca_sign(struct passwd *pw, int argc, char **argv)
 {
+#ifdef ENABLE_PKCS11
 	int i, fd;
 	u_int n;
 	Key *ca, *public;
@@ -1492,6 +1493,10 @@
 	}
 	pkcs11_terminate();
 	exit(0);
+#else
+	fatal("no pkcs11 support");
+	exit(1);
+#endif
 }
 
 static u_int64_t
