# $NetBSD: Makefile,v 1.30 2004/01/23 21:50:46 jmmv Exp $

DISTNAME=	kdeutils-${_KDE_VERSION}
COMMENT=	Utilities for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}
MAKE_ENV+=		EXPORT_SYMBOLS_LDFLAGS="${EXPORT_SYMBOLS_LDFLAGS}"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=             -D__NetBSD_APM__
.endif

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
