# $NetBSD: Makefile,v 1.10 2001/05/22 09:32:27 wiz Exp $
#

DISTNAME=	ebuilder-0.56d
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	x11 devel
MASTER_SITES=	http://web.inter.nl.net/users/eavdmeer/src/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://web.inter.nl.net/users/eavdmeer/index.html
COMMENT=	GUI builder for the Qt library

USE_BUILDLINK_ONLY=	yes
USE_X11=		yes
USE_GMAKE=		yes
MAKEFILE=		GNUmakefile

MAKE_ENV+=		CXXFLAGS="${CXXFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ebuilder ${PREFIX}/bin

.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
