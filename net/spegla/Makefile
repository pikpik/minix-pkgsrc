# $NetBSD: Makefile,v 1.7 2005/04/11 21:47:00 tv Exp $

DISTNAME=		spegla-1.1p4
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://subzero.campus.luth.se/pub/spegla/

MAINTAINER=		jnilsson@ludd.luth.se
COMMENT=		Mirror program for FTP sites (written in C)

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_TRANSFORM+=	rm:-Werror

USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1 \
			share/examples/spegla

.include "../../mk/bsd.pkg.mk"
