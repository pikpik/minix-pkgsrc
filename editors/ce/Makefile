# $NetBSD: Makefile,v 1.7 2004/04/11 08:40:41 snj Exp $
#

.include "Makefile.common"
PKGREVISION=		1

COMMENT+=		, tty version

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

ALL_TARGET=		ce
INSTALL_TARGET=		install man-install

INSTALLATION_DIRS=	bin man/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
