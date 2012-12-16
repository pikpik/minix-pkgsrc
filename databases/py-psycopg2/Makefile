# $NetBSD: Makefile,v 1.21 2012/10/02 21:25:50 asau Exp $

DISTNAME=	psycopg2-2.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/psycopg/tarballs/PSYCOPG-2-4/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://initd.org/psycopg/
COMMENT=	PostgreSQL database adapter for Python
LICENSE=	gnu-lgpl-v3

PYTHON_VERSIONS_INCLUDE_3X=	yes
REPLACE_PYTHON+=		tests/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
