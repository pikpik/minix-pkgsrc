# $NetBSD: Makefile,v 1.17 2011/04/20 09:03:18 roy Exp $

DISTNAME=	kactivities-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	KDE Activity Manager

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=	lib/libkactivities.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
