# $NetBSD: Makefile,v 1.27 2002/05/30 18:45:00 dmcmahill Exp $

PKGNAME=		g${DISTNAME}
PKGREVISION=		1
CATEGORIES+=		gnome

COMMENT=		GNOME version of Midnight Commander, a free Norton Commander Clone

USE_X11BASE=		# defined
CONFIGURE_ARGS+=	--with-tm-x-support
CONFIGURE_ARGS+=	--with-gnome
BUILD_USES_MSGFMT=	yes

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/gmc/C/figs

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../sysutils/mc/Makefile.common"
