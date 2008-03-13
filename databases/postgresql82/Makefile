# $NetBSD: Makefile,v 1.2 2007/10/25 22:00:42 jlam Exp $

PKGNAME=	postgresql82-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql82-client>=${BASE_VERS}:../../databases/postgresql82-client
DEPENDS+=	postgresql82-server>=${BASE_VERS}:../../databases/postgresql82-server

.include "Makefile.common"

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
