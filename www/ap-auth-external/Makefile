# $NetBSD$
#

DISTNAME=	mod_auth_external-${DISTVERS}
PKGNAME=	${APACHE_PKG_PREFIX}-auth-external-${DISTVERS}
CATEGORIES=	www
MASTER_SITES=	http://unixpapa.com/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://unixpapa.com/mod_authnz_external/
COMMENT=	Apache module for external program authentication

PKG_APACHE_ACCEPTED=	apache13 apache2

.include "../../mk/apache.mk"

APACHE_MODULE_NAME=	mod_auth_external.so

.if ${PKG_APACHE} == "apache13"
DISTVERS=	2.1.19
.else
DISTVERS=	2.2.11
.endif

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
