# $NetBSD: Makefile,v 1.14 2004/08/27 06:29:07 jlam Exp $

MODNAME=		mysql
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP extension for MySQL databases

MAINTAINER=		tech-pkg@NetBSD.org

USE_BUILDLINK3=		yes
USE_PHP_EXT_PATCHES=	yes

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/mysql

.include "../../lang/php/ext.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
