$NetBSD$

--- server.c.orig	Sun May 14 05:29:21 2006
+++ server.c
@@ -42,7 +42,9 @@ setup_listeners(struct servent *se, struct ntpd_conf *
 	u_int8_t		*a6;
 	size_t			 sa6len = sizeof(struct in6_addr);
 	u_int			 new_cnt = 0;
+#ifdef IPTOS_LOWDELAY
 	int			 tos = IPTOS_LOWDELAY;
+#endif
 
 	if (conf->listen_all) {
 		if (getifaddrs(&ifa) == -1)
@@ -105,9 +107,11 @@ setup_listeners(struct servent *se, struct ntpd_conf *
 		if ((la->fd = socket(la->sa.ss_family, SOCK_DGRAM, 0)) == -1)
 			fatal("socket");
 
+#ifdef IPTOS_LOWDELAY
 		if (la->sa.ss_family == AF_INET && setsockopt(la->fd,
 		    IPPROTO_IP, IP_TOS, &tos, sizeof(tos)) == -1)
 			log_warn("setsockopt IPTOS_LOWDELAY");
+#endif
 
 		if (bind(la->fd, (struct sockaddr *)&la->sa,
 		    SA_LEN((struct sockaddr *)&la->sa)) == -1)
