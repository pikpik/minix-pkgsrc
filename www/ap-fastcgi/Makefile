# $NetBSD: Makefile,v 1.26 2004/05/08 15:19:18 grant Exp $
#

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/mod_/ap-/}

APACHE_MODULE=	yes
APACHE_MODULE_NAME=	mod_fastcgi.so
APACHE_MANUAL=	htdocs/manual

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
