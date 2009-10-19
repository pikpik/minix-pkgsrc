# $NetBSD: Makefile,v 1.7 2009/07/14 11:14:33 joerg Exp $
#

DISTNAME=	flup-1.0.2
PKGNAME=	${PYPKGPREFIX}-flup-1.0.2
CATEGORIES=	www python
MASTER_SITES=	http://www.saddi.com/software/flup/dist/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://trac.saddi.com/flup
COMMENT=	WSGI support modules

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty

WRKSRC=		${WRKDIR}/${EGG_NAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
