# $NetBSD$

DISTNAME=	ivtools-1.0.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ivtools/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.vectaport.com/ivtools/
COMMENT=	Drawing editors for PostScript, TeX, and web graphics

CONFLICTS+=	dclock-*

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11=	YES

WRKSRC=		${WRKDIR}/${DISTNAME:C/\.[0-9]$//}

pre-install:
	${RM} -f ${WRKSRC}/config/local.def.orig

.include "../../mk/bsd.pkg.mk"
