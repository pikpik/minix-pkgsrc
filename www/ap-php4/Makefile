# $NetBSD: Makefile,v 1.2 2000/12/08 13:16:13 wiz Exp $

.include "../../www/php4/Makefile.common"

PKGNAME=		ap-${DISTNAME}nb1
CATEGORIES+=		www lang

MAINTAINER=		jdolecek@netbsd.org
HOMEPAGE=		http://www.php.net/

DEPENDS+=		php-${PHP_VERS}:../../www/php4
DEPENDS+=		apache>=1.3:../../www/apache

CONFIGURE_ARGS+=	--with-apxs=${LOCALBASE}/sbin/apxs

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libphp4.so \
		${PREFIX}/lib/httpd/mod_php4.so

.include "../../mk/bsd.pkg.mk"
