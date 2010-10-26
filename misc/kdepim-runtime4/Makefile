# $NetBSD: Makefile,v 1.10 2010/09/14 11:02:25 wiz Exp $

#DISTNAME=	kdepim-runtime-${_KDE_VERSION}
DISTNAME=	kdepim-runtime-4.4.7
MASTER_SITES=	${MASTER_SITE_KDE:=kdepim-4.4.7/src/}
CATEGORIES=	misc
COMMENT=	Runtime requirements for the KDE PIM tools

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
