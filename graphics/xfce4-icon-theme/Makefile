# $NetBSD: Makefile,v 1.1.1.1 2005/01/17 12:47:07 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-icon-theme-${XFCE4_VERSION}
CATEGORIES=	graphics
COMMENT=	XFce4 icon themes

.if !empty(MACHINE_PLATFORM:MNetBSD-1.6*)
# The distfile cannot be extracted with tar on NetBSD 1.6.x
BUILD_DEPENDS+=	gtar-base-[0-9]*:../../archivers/gtar-base
GTAR=		${PREFIX}/bin/${GNU_PROGRAM_PREFIX}tar
.endif

.include "../../mk/bsd.pkg.mk"
