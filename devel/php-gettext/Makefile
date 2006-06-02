# $NetBSD: Makefile,v 1.6 2006/02/05 23:08:50 joerg Exp $

MODNAME=		gettext
CATEGORIES+=		devel
COMMENT=		PHP extension for gettext support

CONFLICTS=	php-gettext-[0-9]

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gettext}

.include "../../lang/php/ext.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
