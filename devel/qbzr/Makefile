# $NetBSD: Makefile,v 1.8 2009/09/09 05:44:12 epg Exp $

DISTNAME=	qbzr-${VER}
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/qbzr/0.14/${VER}/+download/
VER=		0.14.3

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://bazaar-vcs.org/QBzr
COMMENT=	GUI front end for Bazaar

DEPENDS+=	${PYPKGPREFIX}-qt4>=4.4:../../x11/py-qt4

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	msgfmt

WRKSRC=		${WRKDIR}/qbzr

PYDISTUTILSPKG=	yes

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
