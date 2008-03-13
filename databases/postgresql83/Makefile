# $NetBSD: Makefile,v 1.1.1.1 2008/03/04 12:41:36 adam Exp $

PKGNAME=	postgresql83-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql83-client>=${BASE_VERS}:../../databases/postgresql83-client
DEPENDS+=	postgresql83-server>=${BASE_VERS}:../../databases/postgresql83-server

.include "Makefile.common"

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
