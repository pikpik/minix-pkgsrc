# $NetBSD: Makefile,v 1.6 2006/02/05 23:10:13 joerg Exp $

MODNAME=		calendar
CATEGORIES+=		misc
COMMENT=		PHP extension for calendar conversion support

CONFLICTS=	php-calendar-[0-9]

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
