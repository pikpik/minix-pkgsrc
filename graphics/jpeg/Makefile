# $NetBSD: Makefile,v 1.15 2000/06/01 11:23:29 rh Exp $
#

DISTNAME=		jpegsrc.v6b
PKGNAME=		jpeg-6b
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.uu.net/graphics/jpeg/

MAINTAINER=		mycroft@netbsd.org
HOMEPAGE=		http://www.ijg.org/

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-static
INSTALL_TARGET=		install install-lib

.include "../../mk/bsd.pkg.mk"
