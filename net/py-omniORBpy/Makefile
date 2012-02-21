# $NetBSD: Makefile,v 1.2 2011/04/21 16:35:27 drochner Exp $

DISTNAME=	omniORBpy-3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=omniorb/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://omniorb.sourceforge.net/
COMMENT=	Python interface to omniORB

PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SUBST+=	PYINC=${PYINC} PYSITELIB=${PYSITELIB}
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++
MAKE_FILE=	GNUmakefile

# This needed to match the setting of PYTHON_VERSION_DEFAULT in
# lang/python/pyversion.mk.
PYTHON_VERSIONS_INCOMPATIBLE+=	${_PYTHON_VERSION_DEFAULT}

.include "../../lang/python/application.mk"
.include "../../net/omniORB/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
