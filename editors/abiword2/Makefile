# $NetBSD$
#

.include "${.CURDIR}/Makefile.common"

PKGNAME=		abiword2-${DIST_VER}
COMMENT=		Abiword Suite 2.0 (GTK+ 2)

CONFIGURE_ARGS+=	--disable-gnome

PLIST_SUBST+=		WITH_GNOME="@comment "

CONFLICTS=		abiword2-gnome-[0-9]*

.include "../../devel/libglade2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
