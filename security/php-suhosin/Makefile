# $NetBSD: Makefile,v 1.4 2011/12/17 13:46:28 obache Exp $
#

MODNAME=		suhosin
DISTNAME=		suhosin-${PECL_VERSION}
PECL_VERSION=		0.9.33
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES=		www
MASTER_SITES=		http://download.suhosin.org/

MAINTAINER=		cg@cgall.de
HOMEPAGE=		http://www.hardened-php.net/suhosin/index.html
COMMENT=		Advanced protection system for PHP installations

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS=		--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
