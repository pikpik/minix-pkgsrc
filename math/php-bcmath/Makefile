# $NetBSD: Makefile,v 1.4 2006/02/05 23:10:03 joerg Exp $

MODNAME=		bcmath
CATEGORIES+=		math
COMMENT=		PHP extension for bc-style arbitrary precision math

CONFLICTS=	php-bcmath-[0-9]

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
