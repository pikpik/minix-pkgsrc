$NetBSD$

--- src/util/inet_addr_local.c.orig	Fri Nov 13 22:06:33 2009
+++ src/util/inet_addr_local.c
@@ -319,7 +319,47 @@ static int ial_siocglif(INET_ADDR_LIST *addr_list,
 }
 
 #else					/* HAVE_SIOCGLIF */
+#ifdef HAS_NWIOGIPCONF
 
+#include <stdlib.h>
+#include <net/netlib.h>
+#include <net/gen/in.h>
+#include <net/gen/ip_io.h>
+
+
+static int ial_getnwiogipconf(INET_ADDR_LIST *addr_list,
+			          INET_ADDR_LIST *mask_list,
+			          int af)
+{
+	int sock;
+        nwio_ipconf_t ipconf;
+    	const char *myname = "ial_getnwiogipconf";
+    	struct sockaddr_in *sa, *mask;
+
+	sock = ial_socket(af);
+	if (sock < 0)
+		return (0);
+	sa = mymalloc(sizeof (*sa));
+	mask = mymalloc(sizeof (*mask));
+	if(ioctl(sock, NWIOGIPCONF, &ipconf) < 0)
+		msg_fatal("%s: ioctl NWIOGIPCONF: %m", myname);
+	if(!(ipconf.nwic_flags & NWIC_IPADDR_SET))
+		return (0);
+	if(mask_list && !(ipconf.nwic_flags & NWIC_NETMASK_SET))
+		return (0);
+	SOCK_ADDR_IN_ADDR(sa).s_addr = ipconf.nwic_ipaddr;
+	SOCK_ADDR_IN_FAMILY(sa) = af;
+	inet_addr_list_append(addr_list, sa);
+	
+	if(mask_list) {
+		SOCK_ADDR_IN_ADDR(mask).s_addr = ipconf.nwic_netmask;
+		SOCK_ADDR_IN_FAMILY(mask) = af;
+		inet_addr_list_append(addr_list, mask);
+	}
+	close(sock);
+}
+#else
+
 /*
  * The classic SIOCGIF* ioctls. Modern BSD operating systems will
  * also return IPv6 addresses through these structure. Note however
@@ -439,6 +479,7 @@ static int ial_siocgif(INET_ADDR_LIST *addr_list,
     return (0);
 }
 
+#endif
 #endif					/* HAVE_SIOCGLIF */
 
 #ifdef HAS_PROCNET_IFINET6
@@ -510,6 +551,7 @@ static int ial_procnet_ifinet6(INET_ADDR_LIST *addr_li
 
 #endif					/* HAS_PROCNET_IFINET6 */
 
+
 /* inet_addr_local - find all IP addresses for this host */
 
 int     inet_addr_local(INET_ADDR_LIST *addr_list, INET_ADDR_LIST *mask_list,
@@ -531,6 +573,8 @@ int     inet_addr_local(INET_ADDR_LIST *addr_list, INE
 	    ial_getifaddrs(addr_list, mask_list, AF_INET);
 #elif defined (HAS_SIOCGLIF)
 	    ial_siocglif(addr_list, mask_list, AF_INET);
+#elif defined(HAS_NWIOGIPCONF)
+            ial_getnwiogipconf(addr_list, mask_list, AF_INET);
 #else
 	    ial_siocgif(addr_list, mask_list, AF_INET);
 #endif
