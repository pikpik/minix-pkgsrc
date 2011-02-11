# $NetBSD: Makefile,v 1.29 2010/01/17 12:02:35 wiz Exp $

DISTNAME=	tcpdump-4.1.1
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcpdump.org/
COMMENT=	Network monitoring tool
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

.include "options.mk"

# not strictly needed
BUILDLINK_API_DEPENDS.libpcap+= libpcap>=1.1.1
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
