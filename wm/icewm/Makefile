# $NetBSD: Makefile,v 1.16 2003/05/03 16:38:12 jmmv Exp $

PKGNAME=		${DISTNAME}
COMMENT=		Small, fast and light-weight window manager

CONFLICTS+=		icewm-gnome-[0-9]* icewm-imlib-[0-9]*

USE_BUILDLINK2=		# defined

CONFIGURE_ARGS+=	--with-gnome-menus=no
CONFIGURE_ARGS+=	--with-imlib=no
CONFIGURE_ARGS+=	--with-xpm=${BUILDLINK_PREFIX.xpm}

.include "Makefile.common"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
