# $NetBSD: Makefile,v 1.10 2007/10/25 22:00:41 jlam Exp $

PKGNAME=	postgresql80-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql80-client>=${BASE_VERS}:../../databases/postgresql80-client
DEPENDS+=	postgresql80-server>=${BASE_VERS}:../../databases/postgresql80-server

.include "Makefile.common"

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
