# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:28 joerg Exp $

MODNAME=		sysvshm
CATEGORIES+=		devel
COMMENT=		PHP extension for SysV shared memory support

CONFLICTS=	php-sysvshm-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
