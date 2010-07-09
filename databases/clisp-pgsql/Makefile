# $NetBSD$
#

CLISP_MODULE=	postgresql

PKGNAME=	clisp-pgsql-$(CLISP_VERSION)
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP PostgreSQL module

MAKE_JOBS_SAFE=	no


.include "../../lang/clisp/module.mk"

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
