# $NetBSD: Makefile,v 1.3 2002/12/24 06:09:47 wiz Exp $

DISTNAME=	psi-0.8.7
CATEGORIES=	chat
MASTER_SITES=	http://belnet.dl.sourceforge.net/sourceforge/psi/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@netbsd.org
HOMEPAGE=	http://psi.affinix.com/
COMMENT=	PSI Jabber Client

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_X11BASE=	yes
HAS_CONFIGURE=	yes

BUILD_DIRS=	${WRKSRC}/src

CONFIGURE_ARGS+= -p ${PREFIX}

BUILDLINK_DEPENDS_METHOD.qt3-tools=	build
# need qt3 3.0.4nb2, for qmake
BUILDLINK_DEPENDS.qt3-tools=		qt3-tools>=3.0.4nb2

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
