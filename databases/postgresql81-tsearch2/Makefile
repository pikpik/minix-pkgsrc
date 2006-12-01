# $NetBSD: Makefile,v 1.2 2006/03/21 06:39:33 martti Exp $

PKGNAME=	postgresql81-tsearch2-${BASE_VERS}
COMMENT=	PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql81-server>=${BASE_VERS}:../../databases/postgresql81-server

.include "../../databases/postgresql81/Makefile.common"

BUILD_DIRS=		${WRKSRC}/contrib/tsearch2/snowball ${WRKSRC}/contrib/tsearch2

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

.include "../../databases/postgresql81-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
