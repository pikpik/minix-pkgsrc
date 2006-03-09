# $NetBSD: Makefile,v 1.6 2006/02/15 18:08:35 drochner Exp $
#

.include "../../print/poppler/Makefile.common"

PKGNAME=		poppler-glib-${POPPLER_VERS}
COMMENT=		PDF rendering library (GLib wrapper)

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/poppler-glib.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
# Don't build the cairo graphics backend.
CONFIGURE_ARGS+=	--disable-cairo-output
# Don't compile poppler qt wrapper.
CONFIGURE_ARGS+=	--disable-poppler-qt
# Don't compile GTK+ test program.
CONFIGURE_ARGS+=        --disable-gtk-test

do-build:
	cd ${WRKSRC}/glib && ${SETENV} ${MAKE_ENV} ${GMAKE}

do-install:
	cd ${WRKSRC}/glib && ${SETENV} ${MAKE_ENV} ${GMAKE} install
	${INSTALL_DATA} ${WRKSRC}/poppler-glib.pc ${PREFIX}/lib/pkgconfig

.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPENDS.poppler+=     poppler>=${POPPLER_VERS}
.include "../../print/poppler/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
