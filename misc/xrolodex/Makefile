# $NetBSD$

DISTNAME=		xrolodex.1.5.motif
PKGNAME=		xrolodex-1.5
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net

WRKSRC=			${WRKDIR}/xrolodex.15
MAKE_ENV+=		XMLIB='-lXm'
USE_MOTIF=		yes
USE_IMAKE=		yes

.include "../../mk/bsd.pkg.mk"
