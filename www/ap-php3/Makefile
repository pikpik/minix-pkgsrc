# $NetBSD: Makefile,v 1.8 2001/05/20 05:23:28 jonb Exp $
#

PKGNAME=		ap-php-${BASE_VERS}
PKGREVISION=		# empty
COMMENT=		Apache module for PHP3

USE_BUILDLINK_ONLY=	yes

.include "../../www/php3/Makefile.common"

DEPENDS+=		php>=${BASE_VERS}:../../www/php3
DEPENDS+=		apache{,6}>=1.3:../../www/apache

CPPFLAGS+=		-DPHP_INTERNAL_FUNCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/libphp3.so ${PREFIX}/lib/httpd/mod_php3.so

.include "../../www/apache/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
