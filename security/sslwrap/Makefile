# $NetBSD: Makefile,v 1.6 2000/02/05 04:53:17 wiz Exp $

DISTNAME=	sslwrap205
PKGNAME=	sslwrap-2.0.5
CATEGORIES=	security net
MASTER_SITES=	http://www.rickk.com/sslwrap/

MAINTAINER=	explorer@netbsd.org
HOMEPAGE=	http://www.rickk.com/sslwrap/

RESTRICTED=	"Crypto; export-controlled"
MIRROR_DISTFILE= no

.include "../../mk/bsd.prefs.mk"

#WRKSRC=		${WRKDIR}/sslwrap205

MAKE_ENV=	SSL_LIBDIR=-L${SSLBASE}/lib SSL_INCDIR=-L${SSLBASE}/include

USE_SSL=	defined

pre-configure:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/sslwrap ${PREFIX}/libexec/sslwrap

.include "../../mk/bsd.pkg.mk"
