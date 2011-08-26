$NetBSD$

--- inet.c.orig	Fri Mar 12 01:56:54 2010
+++ inet.c
@@ -648,6 +648,9 @@ pcap_lookupdev(errbuf)
 #ifndef IF_NAMESIZE
 #define IF_NAMESIZE IFNAMSIZ
 #endif
+#ifndef IFNAMSIZ
+#define IFNAMSIZ 16
+#endif
 	static char device[IF_NAMESIZE + 1];
 	char *ret;
 
@@ -687,6 +690,11 @@ pcap_lookupnet(device, netp, maskp, errbuf)
 	register bpf_u_int32 *netp, *maskp;
 	register char *errbuf;
 {
+#ifdef __minix
+       (void)snprintf(errbuf, PCAP_ERRBUF_SIZE, "pcap_lookupnet not supported under minix");
+       return (-1);
+#else
+
 	register int fd;
 	register struct sockaddr_in *sin4;
 	struct ifreq ifr;
@@ -772,6 +780,7 @@ pcap_lookupnet(device, netp, maskp, errbuf)
 	}
 	*netp &= *maskp;
 	return (0);
+#endif
 }
 
 #elif defined(WIN32)
