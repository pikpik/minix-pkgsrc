# $NetBSD: Makefile,v 1.31 2010/12/02 15:00:03 wiz Exp $

DISTNAME=	docutils-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docutils/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://docutils.sourceforge.net/
COMMENT=	Python tool to generate documents
LICENSE=	public-domain AND 2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-roman>=1.4:../../math/py-roman

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
