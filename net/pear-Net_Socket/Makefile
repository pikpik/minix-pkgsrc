# $NetBSD$

DISTNAME=	Net_Socket-1.0.1
CATEGORIES+=	net

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE= 	http://pear.php.net/package/Net_Socket
COMMENT=	PHP classes to provide Network Socket Interface

.include "../../lang/php/pear.mk"

# used to be bundled before PHP 5.x
.if ${_PHP_VERSION} < 5
PKG_SKIP_REASON=	"${PKGNAME} is part of PHP${_PHP_VERSION}"
.endif

.include "../../mk/bsd.pkg.mk"
