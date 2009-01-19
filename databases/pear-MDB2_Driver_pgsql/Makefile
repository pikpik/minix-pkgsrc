# $NetBSD: Makefile,v 1.2 2008/07/13 17:55:38 tonnerre Exp $

DISTNAME=	MDB2_Driver_pgsql-1.5.0b2
CATEGORIES=	databases

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/MDB2_Driver_pgsql
COMMENT=	Pgsql MDB2 driver

DEPENDS+=	${PHP_PKG_PREFIX}-pgsql-[0-9]*:../../databases/php-pgsql
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2>=2.5:../../databases/pear-MDB2

PEAR_DIRRM_EXCLUDE=	lib/php/MDB2

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
