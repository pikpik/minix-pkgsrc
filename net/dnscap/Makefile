# $NetBSD: Makefile,v 1.16 2011/11/01 06:03:10 sbd Exp $

DISTNAME=		dnscap-134
CATEGORIES=		net
MASTER_SITES=		http://dnscap.dns-oarc.net/

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		https://www.dns-oarc.net/tools/dnscap
COMMENT=		Network capture utility designed specifically for DNS traffic
LICENSE=		isc

GNU_CONFIGURE=		yes

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${MANPREFIX}/man1

.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
