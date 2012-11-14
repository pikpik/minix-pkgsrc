$NetBSD$

--- shlibs/uuid/src/gen_uuid.c.orig	Wed Nov 14 15:31:27 2012
+++ shlibs/uuid/src/gen_uuid.c
@@ -223,6 +223,7 @@ static void get_random_bytes(void *buf, int nbytes)
  */
 static int get_node_id(unsigned char *node_id)
 {
+ifndef __minix
 #ifdef HAVE_NET_IF_H
 	int		sd;
 	struct ifreq	ifr, *ifrp;
@@ -299,6 +300,7 @@ static int get_node_id(unsigned char *node_id)
 		}
 	}
 	close(sd);
+#endif
 #endif
 	return 0;
 }
