# $NetBSD: Makefile,v 1.7 2009/05/19 08:59:12 wiz Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	4.6.0
DISTNAME=	xfce4-dev-tools-${XFCE4_VERSION}
CATEGORIES=	devel
COMMENT=	Xfce development tools
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

USE_TOOLS+=	bash:run
REPLACE_BASH+=	scripts/xdt-commit

MAKE_DIRS+=	${PREFIX}/share/xfce4

.include "../../mk/bsd.pkg.mk"
