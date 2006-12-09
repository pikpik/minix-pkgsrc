# $NetBSD: Makefile,v 1.2 2006/03/21 06:39:33 martti Exp $

PKGNAME=	postgresql82-plpython-${BASE_VERS}
COMMENT=	PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql82-server>=${BASE_VERS}:../../databases/postgresql82-server

.include "../../databases/postgresql82/Makefile.common"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"

BUILD_DIRS=		${WRKSRC}/src/pl/plpython

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

.include "../../databases/postgresql82-client/buildlink3.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
