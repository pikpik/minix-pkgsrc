# $NetBSD: Makefile,v 1.6 2006/02/05 23:08:50 joerg Exp $

MODNAME=		posix
CATEGORIES+=		devel
COMMENT=		PHP extension for POSIX-like functions

CONFLICTS=	php-posix-[0-9]

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
