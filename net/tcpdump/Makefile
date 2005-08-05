# $NetBSD: Makefile,v 1.17 2005/06/12 19:41:45 salo Exp $

DISTNAME=		tcpdump-3.9.3
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.tcpdump.org/
COMMENT=		Network monitoring tool

GNU_CONFIGURE=		YES

.include "options.mk"

# not strictly needed
BUILDLINK_DEPENDS.libpcap+= libpcap>=0.9.3
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
