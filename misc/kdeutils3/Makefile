# $NetBSD: Makefile,v 1.3 2002/08/28 07:15:37 skrll Exp $

DISTNAME=	kdeutils-3.0.3
COMMENT=	Utilities for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK_ONLY=	YES

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && exists(/usr/include/machine/apmvar.h)
.include "../../mk/bsd.prefs.mk"
.endif

post-install:
	${CHMOD} -s ${PREFIX}/bin/efax

.include "../../x11/kde3/buildlink.mk"
.include "../../x11/kdebase3/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
