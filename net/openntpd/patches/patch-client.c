--- client.c.orig	Sun May 14 05:29:21 2006
+++ client.c	Mon Apr  1 17:53:24 2013
--- client.c.orig	Sun May 14 05:29:21 2006
+++ client.c
@@ -115,7 +115,9 @@ client_nextaddr(struct ntp_peer *p)
 int
 client_query(struct ntp_peer *p)
 {
+#ifdef IPTOS_LOWDELAY
 	int	tos = IPTOS_LOWDELAY;
+#endif
 
 	if (p->addr == NULL && client_nextaddr(p) == -1) {
 		set_next(p, error_interval());
@@ -140,9 +142,11 @@ client_query(struct ntp_peer *p)
 			} else
 				fatal("client_query connect");
 		}
+#ifdef IPTOS_LOWDELAY
 		if (p->addr->ss.ss_family == AF_INET && setsockopt(p->query->fd,
 		    IPPROTO_IP, IP_TOS, &tos, sizeof(tos)) == -1)
 			log_warn("setsockopt IPTOS_LOWDELAY");
+#endif
 	}
 
 	/*
