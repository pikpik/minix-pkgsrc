$NetBSD$

--- fad-getad.c.orig	Mon Apr  5 17:54:05 2010
+++ fad-getad.c
@@ -207,19 +207,27 @@ pcap_findalldevs(pcap_if_t **alldevsp, char *errbuf)
 			addr_size = 0;
 			netmask = NULL;
 		}
+#ifdef IFF_BROADCAST
 		if (ifa->ifa_flags & IFF_BROADCAST &&
 		    ifa->ifa_broadaddr != NULL) {
 			broadaddr = ifa->ifa_broadaddr;
 			broadaddr_size = SA_LEN(broadaddr);
-		} else {
+		}
+		else
+#endif
+		{
 			broadaddr = NULL;
 			broadaddr_size = 0;
 		}
+#ifdef IFF_POINTOPOINT
 		if (ifa->ifa_flags & IFF_POINTOPOINT &&
 		    ifa->ifa_dstaddr != NULL) {
 			dstaddr = ifa->ifa_dstaddr;
 			dstaddr_size = SA_LEN(ifa->ifa_dstaddr);
-		} else {
+		}
+		else
+#endif
+		{
 			dstaddr = NULL;
 			dstaddr_size = 0;
 		}
