# $NetBSD: Makefile,v 1.4 2002/08/25 21:50:17 jlam Exp $

DISTNAME=		tcpdump-3.7.2
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.tcpdump.org/
COMMENT=		network monitoring tool

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES

.if exists(/usr/include/netinet/ip6.h)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../net/libpcap/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
