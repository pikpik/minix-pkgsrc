# $NetBSD: Makefile,v 1.2 2006/11/14 13:39:17 joerg Exp $

DISTNAME=	pysqlite-2.3.2
PKGNAME=	${PYPKGPREFIX}-sqlite2-2.3.2
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/pysqlite/releases/2.3/2.3.2/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://initd.org/tracker/pysqlite
COMMENT=	SQLite database adapter for Python

PYDISTUTILSPKG=	yes

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
