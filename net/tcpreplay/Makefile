# $NetBSD: Makefile,v 1.7 2004/10/03 00:18:00 tv Exp $

DISTNAME=	tcpreplay-2.3.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcpreplay/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tcpreplay.sourceforge.net/
COMMENT=	Replay saved tcpdump or snoop files

BUILDLINK_DEPENDS.libpcap+=	libpcap>=0.6

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes

.include "../../devel/libnet11/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
