# $NetBSD: Makefile,v 1.19 2004/07/22 09:16:02 recht Exp $

DISTNAME=	gdmodule.c
PKGNAME=	${PYPKGPREFIX}-gd-1.3
PKGREVISION=	5
CATEGORIES=	graphics python
MASTER_SITES=	http://starship.python.net/~richard/gdmodule/
EXTRACT_SUFX=

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://starship.python.net/~richard/gdmodule/
COMMENT=	Python interface to gd graphics library

EXTRACT_CMD=	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

WRKSRC=		${WRKDIR}
ALL_TARGET=	default
USE_BUILDLINK3=	yes

PYDISTUTILSPKG= yes
PYBINMODULE=    yes

post-patch:
	${SED} 's+@LOCALBASE@+${LOCALBASE}+g' ${FILESDIR}/Setup.in > ${WRKSRC}/setup.py

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
