# $NetBSD$

MODNAME=		calendar
CATEGORIES+=		time
COMMENT=		PHP extension for calendar conversion support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		php-calendar-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
