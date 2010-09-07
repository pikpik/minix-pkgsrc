# $NetBSD: Makefile,v 1.10 2010/02/10 19:34:06 joerg Exp $

DISTNAME=	psycopg2-2.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/psycopg/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://initd.org/projects/psycopg2/
COMMENT=	PostgreSQL database adapter for Python
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
