# $NetBSD: Makefile,v 1.8 2011/11/01 06:01:03 sbd Exp $
#

DISTNAME=		winpdb-1.4.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		devel python
MASTER_SITES=		http://winpdb.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://winpdb.org
COMMENT=		Python GUI debugger
LICENSE=		gnu-gpl-v2 # or later

DEPENDS+=		${PYPKGPREFIX}-wxWidgets>=2.6:../../x11/py-wxWidgets

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		#none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
