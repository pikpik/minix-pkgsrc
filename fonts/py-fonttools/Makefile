# $NetBSD: Makefile,v 1.14 2008/06/12 02:14:29 joerg Exp $
#

DISTNAME=		fonttools-2.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		fonts python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fonttools/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fonttools.sourceforge.net/
COMMENT=		Library for manipulating fonts

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
