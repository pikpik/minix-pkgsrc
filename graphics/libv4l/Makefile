# $NetBSD: Makefile,v 1.1.1.1 2008/09/08 19:07:41 jmcneill Exp $

DISTNAME=	libv4l-0.4.3
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://people.atrpms.net/~hdegoede/

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://people.atrpms.net/~hdegoede/
COMMENT=	Video4Linux userspace library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && !exists(/usr/include/sys/videoio.h)
PLIST.needs_videoio=	yes
INSTALLATION_DIRS+=	include/sys

pre-configure:
	${MKDIR} ${WRKSRC}/include/sys
	cp ${FILESDIR}/videoio.h ${WRKSRC}/include/sys

post-install:
	${INSTALL_DATA} ${FILESDIR}/videoio.h ${DESTDIR}${PREFIX}/include/sys
.endif

PLIST_VARS=	needs_videoio

.include "../../mk/bsd.pkg.mk"
