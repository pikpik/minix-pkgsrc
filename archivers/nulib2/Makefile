# $NetBSD: Makefile,v 1.5 2003/03/29 12:40:02 jmmv Exp $
#

DISTNAME=	nulibdist
PKGNAME=	nulib2-2.0.0
WRKSRC=		${WRKDIR}/nulib2-200
CATEGORIES=	archivers
MASTER_SITES=	http://www.nulib.com/downloads/

MAINTAINER=	tv@poxbox.com
HOMEPAGE=	http://www.nulib.com/
COMMENT=	Handles Apple II ShrinkIt (NuFX) file/disk archives

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--cache-file=${WRKDIR}/config.cache

DIST_SUBDIR=	${PKGNAME_NOREV}

.include "../../mk/bsd.pkg.mk"

# nulib2 needs this to identify a Unixlike system
CFLAGS+=	-D__unix__
